// Deck.h
// Sam Saxon s.saxon@wustl.edu
// Tess Jenkins jenkinstess@wustl.edu
// Contains the creation of the abstract class Deck and the public pure 
//    virtual method.

#pragma once

class Deck{
    public:
        virtual void print(std::ostream& os) = 0;
};
