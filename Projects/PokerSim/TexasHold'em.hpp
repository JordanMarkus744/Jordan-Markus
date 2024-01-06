#include "HandChecker.hpp"
#include <iostream>
#include <vector>
#pragma once

class TexasHoldem : public HandChecker{
    std::vector<std::string> hand;
    HandChecker checker;
    public:

    TexasHoldem(){
        std::vector<std::string> tempChecker;
        do{
            if (tempChecker.size()){ // Removes the last two cards that were inputted on the initial loop. If it's looping a second time, then there was an input error.
                tempChecker.pop_back();
                tempChecker.pop_back();
                std::cout << "One of you're inputs was not a card, please try again." << std::endl;
            }
            std::string card1, card2;
            std::cout << "Input card 1:\t";
            std::cin >> card1;
            std::cout << "\nInput card 2:\t";
            std::cin >> card2;
            tempChecker.push_back(card1);
            tempChecker.push_back(card2);
        }while(!checker.cardChecker(tempChecker));

        hand = tempChecker; // Once tempChecker has passed the card checker, i want our hand variable to carry that data.

        checker.GenerateGames(hand);
        
    }

    // We still need to make the function that will generate 1000 games using your deck and record the win loss percentage.
};