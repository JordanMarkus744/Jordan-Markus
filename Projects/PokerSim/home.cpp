#include <iostream>
#include <vector>
#include "TexasHold'em.hpp"


/*
This app will have many different types of poker inside, and when given the cards you have and the cards that are on the table, 
will tell you how likely you are to win.
Texas Hold'em -- Omaha -- Seven Card Stud -- 2-7 Triple Draw -- OFC
*/

int main(){
    short int choice;
    std::cout << "Are you playing Texas Holdem(1), Omaha(2), Seven Card Stud(3), 2-7 Triple Draw(4) or OFC(5)" << std::endl;
    std::cin >> choice;
    while(choice < 1 || choice > 5){
        std::cout << "\nThat was not a correct input" << std::endl;
        std::cout << "\n\nAre you playing Texas Holdem(1), Omaha(2), Seven Card Stud(3), 2-7 Triple Draw(4) or OFC(5)" << std::endl;
        std::cin >> choice;
    }
    if (choice == 1){
        TexasHoldem game;
    }
    else if (choice == 2){
        return 0;
    }
    else if (choice == 3){
        return 0;
    }
    else if (choice == 4){
        return 0;
    }
    else{
        return 0;
    }

    return 0;
}