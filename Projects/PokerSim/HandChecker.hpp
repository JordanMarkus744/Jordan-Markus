// This will simulate 1000 games and show your win percentage with the hand you have.
#include <vector>
#include <iostream>
#include <random>
#include <time.h>
#include "PlayerCreater.hpp"
#pragma once

class HandChecker{


    public:

    bool cardChecker(std::vector<std::string> hand){
        for (auto itr : hand){
            if (!(itr.size() == 2 && // this if statement check to see if everything is formatted right.
            ((itr[0] >= '2' && itr[0] <= '9') || itr[0] == 'T' || itr[0] == 'J' || itr[0] == 'Q' || itr[0] == 'K' || itr[0] == 'A') &&
            (itr[1] == 'h' || itr[1] == 'c' || itr[1] == 'd' || itr[1] == 's'))) {
                return false;
            }
        }
        return true;
    }

    void GenerateGames(std::vector<std::string> hand, std::vector<std::string> pile = {}){ // The pile vector is new and may go away, but it's so the user can input any cards that
                                                                                      // have been laid down on the pile so far.
        double wins = 0, losses = 0;

        std::vector<std::string> usedCards; // this vector stores all of the already used cards so we don't have overlapping cards being played at once;
        std::vector<std::string> Deck = {"Ah", "Ad", "Ac", "As",
                                        "2h", "2d", "2c", "2s",
                                        "3h", "3d", "3c", "3s",
                                        "4h", "4d", "4c", "4s",
                                        "5h", "5d", "5c", "5s",
                                        "6h", "6d", "6c", "6s",
                                        "7h", "7d", "7c", "7s",
                                        "8h", "8d", "8c", "8s",
                                        "9h", "9d", "9c", "9s",
                                        "Th", "Td", "Tc", "Ts",
                                        "Jh", "Jd", "Jc", "Js",
                                        "Qh", "Qd", "Qc", "Qs",
                                        "Kh", "Kd", "Kc", "Ks"};
            
            std::vector<std::string> CurrentDeck = Deck;
            std::vector<Player> playersVec;
            enum combos {HighCard = 1, OnePair, TwoPair, ThreeOfaKind, Straight, Flush, FullHouse, FourOfaKind, StraightFlush};
            enum cardRankings {two = 2, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace};


            // We now need to take away the cards from the deck that the user has in their hand.
            for (int i = 0; i < hand.size(); i++){
                for (int j = 0; j < CurrentDeck.size(); j++){
                    if (hand[i] == CurrentDeck[j]){
                        CurrentDeck[j] = "";
                        usedCards.push_back(hand[i]);
                    }
                }
            }

            // CHANGE THE 1 TO 1000 WHEN DONE TESTING
            for (int iterations = 0; iterations < 1; iterations++){ // This is the for loop that will generate every simulated poker match. Each poker match will have
                                                                        // 5 other 'Players' and a randomly generated pile. Then it will determine if the user's hand wins or loses

                srand(time(NULL));

                // Now let's create the pile, if the pile vector is empty, then we will pull 5 random cards from the current deck, however if there are some cards in the 
                // pile vector, then we will draw 5 - pile.size() cards from the current deck and we will add the random cards to the pile vector and make a new pile vector

                std::vector<std::string> currentPile = pile;

                for(int i = 0; i < currentPile.size(); i++){ // this makes sure that any card that is present in the pile is accounted for in the currentDeck
                    for (int j = 0; j < CurrentDeck.size(); j++){
                        if (currentPile[i] == CurrentDeck[j]){
                            CurrentDeck[j] = "";
                        }
                    }
                }


                for (int i = currentPile.size(); i < 5; i++){ // if currentPile.size() == 3, then we want to generate 2 more cards to put into the pile.
                    int index = rand() % 56;
                    while(CurrentDeck[index] == ""){
                        index = rand() % 56;
                    }
                    currentPile.push_back(CurrentDeck[index]);
                    CurrentDeck[index] = "";
                }



                for (int i = 0; i < 5; i++){ // Generating the Players
                    int c1 = rand() % 56;
                    while(CurrentDeck[c1] == ""){ // if the card is already taken, then loop until we find a card that hasn't been taken
                        c1 = rand() % 56;
                    }

                    int c2 = rand() % 56;
                    while(CurrentDeck[c2] == "" && c1 != c2){
                        c2 = rand() % 56;
                    }
                    Player p(CurrentDeck[c1],CurrentDeck[c2]);
                    playersVec.push_back(p);
                    CurrentDeck[c1] = "";
                    CurrentDeck[c2] = "";
                }
            
                
                // NOW I HAVE TO CHECK FOR COMBOS WITH ALL HANDS THEN DETERMINE IF ITS A WIN OR A LOSS FOR THE USER'S HAND, THEN RESET 


                //------------------------------------------------------------------ This is just for testing so remove this when everything is working
                for (int i = 0; i < 5; i++){
                    std::cout << "\nPlayer " << i+1 << "s hand is: " << playersVec[i].getCard1() << ", " << playersVec[i].getCard2() << std::endl;
                }
                std::cout << "\nUser's hand is: " << hand[0] << ", " << hand[1] << std::endl;
                std::cout << "Pile is: " << std::endl;
                for (int i = 0; i < 5; i++){
                    std::cout << currentPile[i] << ", ";
                }
                //----------------------------------------------------------------------------------------------------------------------------------------

                

            }

        }
};