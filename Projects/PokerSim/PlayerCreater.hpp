#include <string>
#include <iostream>
#pragma once

class Player
{
    std::string card1;
    std::string card2;
    int combo;   // This holds the number corresponding to what combo the Player has
    int ranking; // Ranking var holds the number of the highest card in hand where a 2 card = 2 and an Ace = 14. This should be useful when determining winners

public:
    Player(std::string c1, std::string c2) : card1(c1), card2(c2){};

    Player() : card1(""), card2(""){};

    std::string getCard1()
    {
        return card1;
    }

    std::string getCard2()
    {
        return card2;
    }

    int getCombo()
    {
        return combo;
    }

    int getRanking()
    {
        return ranking;
    }

    void setCard1(std::string card1)
    {
        this->card1 = card1;
    }

    void setCard2(std::string card2)
    {
        this->card2 = card2;
    }

    void setCombo(int combo)
    {
        this->combo = combo;
    }

    void setRanking(int ranking)
    {
        this->ranking = ranking;
    }
};