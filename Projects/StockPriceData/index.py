import pandas as pd
from ally import *
import datetime
import mysql.connector
import time
import pandas_market_calendars as mcal

CONSUMER_KEY = "..."
CONSUMER_SECRET = "..."
OAUTH_TOKEN = "..."
OAUTH_SECRET = "..."

if __name__ == '__main__':
    # markets open: 9:30AM EST
    # markets close: 4:00PM EST
    # just going to assume they all have the same trading days

    with open('log.dat', 'a') as f:
        f.write("Starting API script on {}\n".format(str(datetime.datetime.now().replace(microsecond=0))))
        nyse = mcal.get_calendar("NYSE")
        today = datetime.datetime.strftime(datetime.datetime.today(), '%Y-%m-%d')
        sched = nyse.schedule(start_date=today, end_date=today)
        now = datetime.datetime.now()
        m_open = now.replace(hour=7, minute=30, second=0, microsecond=0)
        m_close = now.replace(hour=14, minute=0, second=0, microsecond=0)
        if sched.shape[0] == 0 or now < m_open or now > m_close: # check if open for day
            f.write("\tThe market is closed, exiting...\n\n")
            exit()

    ally = AllyAPI(OAUTH_SECRET, OAUTH_TOKEN, CONSUMER_KEY, response_format="json")
    snp = pd.read_csv('/home/pi/stock_data_api/sp500tickers.csv')['symbol']
    russel = pd.read_csv('/home/pi/stock_data_api/russel2000.csv')['symbol']

    # multiple tickers counts as one request! how many can we do at once?
    # the limit is ~495 tickers per request; we'll use 400 to be safe
    tickers_per_request = 400
    tickers = snp.tolist()
    tickers.extend(russel.tolist())
    tickers = list(dict.fromkeys(tickers))
    ticker_size = len(tickers)
    tickers = [tickers[x:x+tickers_per_request] for x in range(0, len(tickers), tickers_per_request)]

    # save all the data first so the fetches are as close to the minute as possible
    # and aren't slowed down by database writes
    start = time.time()
    data_to_enter = []
    for ticker_list in tickers:
        quote_request = QuotesRequest(symbols=ticker_list)
        response = quote_request.execute(ally)
        fetch_time = datetime.datetime.now().replace(microsecond=0)
        for quote in response.get_quotes():
            # ticker, volume of last trade, cumulative volume, last trade price, bid price, ask price
            if quote.symbol != 'na':
                incr_vl = float(quote.incr_vl) if quote.incr_vl != '' else 0
                vl = float(quote.vl) if quote.vl != '' else 0
                data_to_enter.append((quote.symbol, incr_vl, vl, float(quote.last), float(quote.bid), float(quote.ask), str(fetch_time)))
    api_end = time.time()

    db_start = time.time()
    database = mysql.connector.connect(
        ...
    )
    cursor = database.cursor()

    # seconds to complete so we tried to find faster ways to perform the insert.
    stock_data_insert_sql = \
        "INSERT INTO stock_data (ticker, last_trade_volume, cumulative_volume, last_trade_price, bid_price, ask_price, datetime) \
        VALUES (%s, %s, %s, %s, %s, %s, %s);"

    # cut the database time from ~163 seconds to ~0.89 seconds
    # entire script runs in 11.019s
    try:
        cursor.executemany(stock_data_insert_sql, data_to_enter)
        database.commit()
    except Exception as e:
        with open('/home/pi/stock_data_api/log.dat', 'a') as f:
            f.write("\tError writing to database:\n")
            f.write('\t' + str(e))
            f.write('\n')
        database.rollback()

    db_end = time.time()

    with open('/home/pi/stock_data_api/log.dat', 'a') as f:
        f.write("\tScript Completed. Timing: {}\tAPI Time: {}\tDB Time: {}\n\n".format((db_end - start), (api_end - start), (db_end - db_start)))