#include "PinochleGame.h"
#define SUCCESS 0

PinochleGame::PinochleGame(int argc, const char* argv[]) : Game(argc, argv) {
    for(int i = 0; i < argc-2; ++i){
        CardSet<PinochleRank, Suits> cs;
        _curHand.push_back(cs);
    }
}

void PinochleGame::deal() {

    typename std::vector< CardSet<PinochleRank, Suits> >::iterator it;

    while (!_pDeck.is_empty()) {
        for (it = _curHand.begin(); it < _curHand.end(); it++) {
            _pDeck >> (*it);
            _pDeck >> (*it);
            _pDeck >> (*it); // need to check if empty so program doesn't crash
        }
    }
    
}

int PinochleGame::play() {
    
    _pDeck.shuffle();
    deal();

    //print player names and their cards
    print_players();

    //collect cards from players
    collect_all();

    std::string input;
    std::cout << "end game? " << std::endl;
    std::cin >> input;
    
    if (input == "yes") {
        return SUCCESS;
    }

    return play();
}

void PinochleGame::print_players() {
    typename std::vector< CardSet<PinochleRank, Suits> >::iterator it = _curHand.begin();
    std::vector<std::string>::iterator p = Game::players.begin();
    
    while (it < _curHand.end()) {
        std::cout << (*p) << std::endl;
        (*it).print(std::cout, 100);
        std::cout << std::endl;

        p++;
        it++;
    }
}

void PinochleGame::collect_all() {
    typename std::vector< CardSet<PinochleRank, Suits> >::iterator it;
    for (it = _curHand.begin(); it < _curHand.end(); it++) {
        _pDeck.collect(*it);
    }
}