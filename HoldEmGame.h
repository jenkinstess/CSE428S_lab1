#pragma once
#include "Game.h"

enum class HoldEmState{
    preflop, flop, turn, river, undefined
};

class HoldEmGame : public Game {

public:
    
    virtual int play();
protected:
    HoldEmDeck deck; 
    HoldEmState state;
    virtual void deal();
    std::vector< CardSet<HoldEmRank, Suits> > hands;
    void print_players();
    void collect_all();

};