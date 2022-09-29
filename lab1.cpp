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

int main(int argc, const char* argv[]){
    
    //HoldEmDeck h;
    PinochleDeck p;

    //h.shuffle();
    //p.shuffle();

    //h.print(std::cout, 100);
    p.print(std::cout, 100);
    std::cout << std::endl;

    PinochleGame g(argc, argv);
    g.play();

    return SUCCESS; 
}
