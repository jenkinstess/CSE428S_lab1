#include "HoldEmGame.h"
#define HAND_SIZE 2
#define SUCCESS 0

HoldEmGame::HoldEmGame(int argc, const char* argv[]) : Game(argc, argv) {
    for(int i = 0; i < argc-2; ++i){
        CardSet<HoldEmRank, Suits> cs;
        hands.push_back(cs);
    }

    state = HoldEmState::preflop;
}


void HoldEmGame::deal() {

    switch (state) {
        case HoldEmState::preflop: {

            // deal 2 cards to each player
            typename std::vector< CardSet<HoldEmRank, Suits> >::iterator it;
            for (int i = 0; i < HAND_SIZE; ++i) {
                for (it = hands.begin(); it < hands.end(); ++it) {
                    deck >> (*it);
                }
            }

            state = HoldEmState::flop;
            break;
        }
        case HoldEmState::flop: {

            deck >> board;
            deck >> board;
            deck >> board;

            state = HoldEmState::turn;
            break;
        }   
        case HoldEmState::turn: {

            deck >> board;

            state = HoldEmState::river;
            break;
        }
        case HoldEmState::river: {

            deck >> board;

            state = HoldEmState::undefined;
            break;
        }
        default:
            break;
    }

}


int HoldEmGame::play() {
    deck.shuffle();
    state = HoldEmState::preflop;

    deal();
    print_players();

    deal();
    std::cout << "BOARD (flop): ";
    board.print(std::cout, 100);

    deal();
    std::cout << "BOARD (turn): ";
    board.print(std::cout, 100);

    deal();
    std::cout << "BOARD (river): ";
    board.print(std::cout, 100);

    collect_all();

    std::string input;
    std::cout << "end game? " << std::endl;
    std::cin >> input;
    
    if (input == "yes") {
        return SUCCESS;
    }

    return play();
}


void HoldEmGame::print_players() {
    typename std::vector< CardSet<HoldEmRank, Suits> >::iterator it = hands.begin();
    std::vector<std::string>::iterator p = Game::players.begin();
    
    while (it < hands.end()) {
        std::cout << (*p) << std::endl;
        (*it).print(std::cout, 100);
        std::cout << std::endl;

        p++;
        it++;
    }
}


void HoldEmGame::collect_all() {
    typename std::vector< CardSet<HoldEmRank, Suits> >::iterator it;
    for (it = hands.begin(); it < hands.end(); it++) {
        deck.collect(*it);
    }

    deck.collect(board);
}