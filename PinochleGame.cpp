#include "PinochleGame.h"

PinochleGame::PinochleGame(int argc, const char* argv[]) : Game(argc, argv) {
    for(int i = 0; i < argc; ++i){
        _curHand.push_back(CardSet<PinochleRank, Suits> cs);
    }
}

void PinochleGame::deal() {
    for (int i = 0; !_pDeck.is_empty(); i+3){
        _curHand.get(i) >> _pDeck.get(i);
        _curHand.get(i) >> _pDeck.get(i+1);
        _curHand.get(i) >> _pDeck.get(i+2);
    }
    
}