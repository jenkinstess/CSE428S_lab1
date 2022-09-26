#pragma once
#include <string>
#include <vector>

class Game {
public:
    Game(int argc, const char* argv[]);
    virtual int play() = 0;
protected:
    std::vector<std::string> players;
};