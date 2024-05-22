#include "HandChecker.hpp"
#include <iostream>
#include <vector>
#pragma once

class TexasHoldem : public HandChecker
{
    std::vector<std::string> hand;
    std::vector<std::string> pile;

public:
    TexasHoldem()
    {
        HandChecker checker;
        std::vector<std::string> tempChecker;
        bool isFull = false;
        do
        {
            if (tempChecker.size())
            { // Removes the last two cards that were inputted on the initial loop. If it's looping a second time, then there was an input error.
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
        } while (!checker.cardChecker(tempChecker));

        // Get the pile from the user
        while (!isFull) 
        {
            if (pile.size() == 5)
            {
                isFull = true;
                break;
            }
            std::string pileCard;
            std::cout << "Please input a card from your current pile, if there isnt one, then input '0'" << std::endl;
            std::cin >> pileCard;

            if (pileCard == "0")
            {
                isFull = true;
            }
            else
            {
                if (pileCard == tempChecker[0] || pileCard == tempChecker[1])
                {
                    std::cout << "That card is already in your hand, you need to pick other cards." << std::endl;
                }
                else
                {
                    pile.push_back(pileCard);
                    if (!checker.cardChecker(pile))
                    {
                        std::cout << "Not a valid card!" << std::endl;
                        pile.pop_back();
                    }
                }
            }
        }

        hand = tempChecker; // Once tempChecker has passed the card checker, i want our hand variable to carry that data.
        tempChecker = {}; // remove the data in tempChecker
        checker.GenerateGames(hand, pile);
    }

    // We still need to make the function that will generate 1000 games using your deck and record the win loss percentage.
};