// Deck.h
// Sam Saxon s.saxon@wustl.edu
// Tess Jenkins jenkinstess@wustl.edu
// Contains the creation of the abstract class Deck and the public pure 
//    virtual method.

#pragma once
#include "CardSet_T.h"

template <typename R, typename S> 
class Deck : public CardSet<R,S>{
public:
    void shuffle();
    void collect(CardSet<R,S>& cs);
};

#ifdef TEMPLATE_HEADERS_INCLUDE_SOURCE
#include "Deck_T.cpp"
#endif