// PinochleDeck.h
// Sam Saxon s.saxon@wustl.edu
// Tess Jenkins jenkinstess@wustl.edu
// Contains shift and increment operator declarations, the inheritence of the abstract class,
//   and the enumeration for the ranks of pinochle

#pragma once
#include "Card_T.h"
#include "Deck.h"
#include <vector>
#include <ostream>

enum class PinochleRank{
    nine, jack, queen, king, ten, ace, undefined
};

class PinochleDeck : public Deck {
    private:
	std::vector< Card<PinochleRank, Suits> > cards;
    public:
	PinochleDeck();
	void print(std::ostream& os);
};

PinochleRank operator++(PinochleRank& _rank, int);

std::ostream& operator<<(std::ostream& os, const PinochleRank& pinRank);



