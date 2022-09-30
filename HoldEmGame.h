#pragma once
#include "HoldEmDeck.h"
#include "Game.h"

enum class HoldEmState{
    preflop, flop, turn, river, undefined
};

class HoldEmGame : public Game {

public:
    HoldEmGame(int argc, const char* argv[]);
    virtual int play();
protected:
    HoldEmDeck deck; 
    HoldEmState state;
    virtual void deal();
    std::vector< CardSet<HoldEmRank, Suits> > hands;
    CardSet<HoldEmRank, Suits> board;
    void print_players();
    void collect_all();

};