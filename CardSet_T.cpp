#include "CardSet_T.h"
#include <iostream>

// template <typename R, typename S>
// CardSet<R,S>::CardSet(R _rank, S _suit) : rank (_rank), suit (_suit) {
// }

template <typename R, typename S>
void CardSet<R,S>::print(std::ostream& os, size_t size){
    
    for(auto i = typename std::vector< Card<R,S> >::iterator begin(); i != typename vector< Card<R,S> >::iterator end(); ++i){
        os << i << " ";
    }
    os << std::endl;

}
