#include "Game.h"

Game::Game(int argc, const char* argv[]) {
    //parameters passed directly from command line ***

    std::vector<std::string> temp;
    for (int i = 2; i < argc; ++i) {
        players.push_back(argv[i]);
    }

    players = temp;
}