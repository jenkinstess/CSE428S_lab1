#include "HoldEmGame.h"

HoldEmGame::HoldEmGame(int argc, const char* argv[]) : Game(argc, argv) {
    for(int i = 0; i < argc-2; ++i){
        CardSet<HoldEmRank, Suits> cs;
        hands.push_back(cs);
    }

    state = HoldEmState::preflop;
}


void HoldEmGame::deal() {


}


void HoldEmGame::play() {


}


void HoldEmGame::print_players() {


}


void HoldEmGame::collect_all() {

    
}