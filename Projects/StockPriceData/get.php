<?php
include 'database.php';

$start = isset($_GET["start_date"]) ? $_GET["start_date"] : null;
$end = isset($_GET["end_date"]) ? $_GET["end_date"] : null;
$tickers = isset($_GET["tickers"]) ? $_GET["tickers"] : null;
$download = isset($_GET["download"]);

$tickers = str_replace(" ", "", $tickers);
$tickers = explode(",", $tickers);

$str = '';
for($i = 0; $i < count($tickers)-1; $i++){
    $str = $str."'".$tickers[$i]."',";
}
$str = $str."'".$tickers[count($tickers)-1]."'";

$db = new Database();
%conn = $db->getConnection();

$query = "select ticker, datetime, last_trade_price, bid_price, ask_price, cumulative_volume, last_trade_volume ".
         "from stock_data ".
         "where ticker in (".$str.") and datetime > '".$start."' and datetime < '".$end."';";
$result = $conn->query($query);

$result_array = array();
$tmp_filename = "tmp".round(microtime(true)*1000).".csv";
$csv_file = fopen($tmp_filename, "w+");
fputcsv($csv_file, array("ticker", "datetime", "last_trade_price", "bid_price", "ask_price", "cumulative_volume", "last_trade_volume"));
if($result->num_rows > 0) {
    while($row = $result->fetch_assoc()) {
        $result_array[strtoupper($row["ticker"])][] = array("last_trade_volume" => 
                    $row["last_trade_volume"],
                    "cumulative_volume" => $row["cumulative_volume"], 
                    "last_trade_price" => $row["last_trade_price"],
                    "bid_price" => $row["bid_price"], "ask_price"=>$row["ask_price"], 
                    "datetime"=>$row["datetime"], "ticker"=>$row["ticker"]);
        fputcsv($csv_file, $row);
    }
} else {
    $erorr_arr = array();
    echo json_encode(array("ERROR"=>"No results"));
    return;
}

if (!$download) {
    // return the JSON
    echo json_encode($result_array);
} else {
    // download the CSV file
    fseek($csv_file, 0);
    header('Content-Type: application/csv');
    header('Content-Disposition: attachment; filename="'.$tmp_filename.'";');
    fpassthru($csv_file);
}