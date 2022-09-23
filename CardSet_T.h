#pragma once
#include "Suit.h"
#include "Card_T.h"
#include "Deck_T.h"
#include <vector>

template <typename R, typename S> class CardSet{
    public:
        // R rank;
        // S suit;
        // CardSet(R _rank, S _suit);
        void print(std::ostream& os, size_t size);
    protected:
        std::vector< Card <R, S> > cards;
};

#ifdef TEMPLATE_HEADERS_INCLUDE_SOURCE
#include "CardSet_T.cpp"
#endif