// lab0.cpp
// Sam Saxon s.saxon@wustl.edu
// Tess Jenkins jenkinstess@wustl.edu
// Contains the main function that prints the suit and rank for all the cards for
//   poker and pinochle

#include "HoldEmDeck.h"
#include "PinochleDeck.h"
#include <iostream>
#define SUCCESS 0

int main(){
    
    HoldEmDeck h;
    PinochleDeck p;

    h.print(std::cout, 52);
    p.print(std::cout, 48);

    return SUCCESS; 
}
