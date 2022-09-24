#include "Game.h"

Game::Game(int argc, char* argv[]) {
    //parameters passed directly from command line ***

    std::vector<std::string> temp;
    for (int i = 1; i < argc; ++i) {
        players.push_back(argv[i]);
    }

    players = temp;
}