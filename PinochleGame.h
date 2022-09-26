#pragma once
#include "PinochleDeck.h"
#include "CardSet_T.h"
#include "Game.h"

class PinochleGame : public Game{
    public:
        PinochleGame(int argc, const char* argv[]);
        virtual int play();

    protected:
        PinochleDeck _pDeck; 
        std::vector< CardSet<PinochleRank, Suits> > _curHand;
        virtual void _deal();
};