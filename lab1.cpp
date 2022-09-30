// lab0.cpp
// Sam Saxon s.saxon@wustl.edu
// Tess Jenkins jenkinstess@wustl.edu
// Contains the main function that prints the suit and rank for all the cards for
//   poker and pinochle

#include "HoldEmGame.h"
#include "PinochleGame.h"
#include <iostream>
#include <memory>
#include <string.h>
#define SUCCESS 0
#define PINOCHLEPLAYERS 6 
#define MINHOLDEMPLAYERS 4
#define MAXHOLDEMPLAYERS 11
#define INCORRECTINPUT 1
#define NULLGAME 2

std::shared_ptr<Game> create(int argc, const char* argv[]);

int main(int argc, const char* argv[]) {

    if (argc < 2) {
        std::cout << "usage: filename gamename playername1 playername2 ..." << std::endl;
        return INCORRECTINPUT;
    }
    
    if (((strcmp(argv[1],"Pinochle") == 0) && argc == PINOCHLEPLAYERS) 
        || (((strcmp(argv[1], "HoldEm") == 0) && (argc >= MINHOLDEMPLAYERS && argc <= MAXHOLDEMPLAYERS)))) {
            
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
        std::cout << "usage: ./lab1 gamename playername1 playername2 ..." << std::endl;
        return INCORRECTINPUT;
    }

    return SUCCESS; 
}

std::shared_ptr<Game> create(int argc, const char* argv[]) {
    
    std::shared_ptr<Game> game1;

    if (strcmp(argv[1],"Pinochle") == 0 ) {
        game1 = std::make_shared<PinochleGame>(argc, argv);
    }
    else {
        game1 = std::make_shared<HoldEmGame>(argc, argv);
    }

    return game1;
}