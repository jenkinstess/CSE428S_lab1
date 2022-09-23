// HoldEmDeck.h
// Sam Saxon s.saxon@wustl.edu
// Tess Jenkins jenkinstess@wustl.edu
// Contains shift and increment operator declarations, the inheritence of the abstract class,
//   and the enumeration for the ranks of poker

#pragma once
#include "Card_T.h"
#include "Deck.h"
#include <vector>
#include <ostream>

enum class HoldEmRank{
    two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace, undefined
};

class HoldEmDeck : public Deck {
    private:
	std::vector< Card<HoldEmRank, Suits> > cards;
    public:
	HoldEmDeck();
	void print(std::ostream& os);
};

HoldEmRank operator++(HoldEmRank& _rank, int);

std::ostream& operator<<(std::ostream& os, const HoldEmRank& _rank);

