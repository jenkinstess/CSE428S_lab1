// lab0.cpp
// Sam Saxon s.saxon@wustl.edu
// Tess Jenkins jenkinstess@wustl.edu
// Contains the main function that prints the suit and rank for all the cards for
//   poker and pinochle

#include "HoldEmDeck.h"
#include "PinochleDeck.h"
#include "PinochleGame.h"
#include <iostream>
#define SUCCESS 0

#define PINOCHLEPLAYERS 6 
#define MINHOLDEMPLAYERS 4
#define MAXHOLDEMPLAYERS 11
#define INCORRECTINPUT 1
#define NULLGAME 2

int main(int argc, const char* argv[]) {
    
    if ((argv[1].equals("Pinochle") && argc == PINOCHLEPLAYERS)
        || (argv[1].equals("HoldEm") && (argc >= MINHOLDEMPLAYERS && argc <= MAXHOLDEMPLAYERS))) {
            
            std::shared_ptr<Game> gamePtr = create(argc, argv);

            if (gamePtr) {
                return gamePtr->play();
            }
            else {
                std::cout << "No game created" << std::endl;
                return NULLGAME;
            }
    }
    else{
        std::cout << "usage: filename gamename playername1 playername2 ..." << std::endl;
        return INCORRECTINPUT;
    }

    return SUCCESS; 
}

std::shared_ptr<Game> create(int argc, const char* argv[]) {
    
    std::shared_ptr<Game> game1;

    if (argv[1].equals("Pinochle")) {
        game1 = std::make_shared<PinochleGame>(argc, argv);
    }
    else (argv[1].equals("HoldEm")) {
        game1 = std::make_shared<HoldEmGame>(argc, argv);
    }

    return game1;
}
