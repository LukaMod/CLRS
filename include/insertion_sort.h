//
// Created by Luka on 2018/8/17.
//

#ifndef CLRS_INSERTION_SORT_H
#define CLRS_INSERTION_SORT_H

#include <functional>
#include <iterator>

template <class BidirectionalIt, class Compare = std::less<>>
void insertionSort(
        BidirectionalIt first,
        BidirectionalIt last,
        Compare compare = Compare()
                ) {
    if (std::distance(first, last) < 2)
        return;

    BidirectionalIt i = first;
    for (++i; i != last; ++i) {
        auto key = *i;
        BidirectionalIt j = i, k = j;
        for (--k; j != first && compare(key, *k); --j, --k)
            *j = std::move(*k);
        *j = std::move(key);
    }
}

#endif //CLRS_INSERTION_SORT_H
