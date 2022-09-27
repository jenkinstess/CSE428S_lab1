#include "PinochleGame.h"

PinochleGame::PinochleGame(int argc, const char* argv[]) : Game(argc, argv) {
    for(int i = 0; i < argc; ++i){
        CardSet<PinochleRank, Suits> cs;
        _curHand.push_back(cs);
    }
}

void PinochleGame::deal() {

    typename std::vector< CardSet<PinochleRank, Suits> >::iterator it;
    typename std::vector< Card<PinochleRank, Suits> >::iterator it1 = _pDeck.begin();
    while (it1 != _pDeck.end()) {
        for (it = _curHand.begin(); it < _curHand.end(); it++) {

            it >> it1;
            it >> it1++;
            it >> it1++;
            
        }
    }
    
}