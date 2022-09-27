#include "CardSet_T.h"
#include <iostream>
#include <iterator>

template <typename R, typename S>
void CardSet<R,S>::print(std::ostream& os, size_t size){
    
    typename std::vector< Card<R, S> >::iterator it;
    for(it = cards.begin(); it < cards.end(); it++){
        if (size == 0) {break;}
        --size;

        os << *it << " ";
    }

    os << std::endl;

}

template <typename R, typename S>
CardSet<R,S>& CardSet<R,S>::operator>>(CardSet<R,S>& cs) {

    if (is_empty()) {
        //throw runtime exception
    }
    

    // get the last element in the vector
    // push this element onto cs, the vector cardset
    // then do pop_back 
    cs.cards.push_back(cards.back());
    cards.pop_back();

    return *this;
}

template <typename R, typename S>
bool CardSet<R,S>::is_empty() {
    return cards.empty();
}
