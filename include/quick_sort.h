//
// Created by Luka on 2018/8/17.
//

#ifndef CLRS_QUICK_SORT_H
#define CLRS_QUICK_SORT_H

#include <functional>
#include <iterator>

template <class BidirectionalIt, class Compare>
BidirectionalIt part(
        BidirectionalIt first,
        BidirectionalIt last,
        Compare compare
) {
    BidirectionalIt x = last;
    auto key = *--x;
    BidirectionalIt i = first;

    for (BidirectionalIt j = first; j != x; ++j) {
        if (!compare(key, *j))
            std::swap(*j, *i++);
    }
    std::swap(*i, *x);
    return i;
}

template <class BidirectionalIt, class Compare = std::less<>>
void quickSort(
        BidirectionalIt first,
        BidirectionalIt last,
        Compare compare = Compare()
) {
    if (std::distance(first, last) > 1) {
        BidirectionalIt q = part(first, last, compare);
        quickSort(first, q, compare);
        quickSort(++q, last, compare);
    }
}

#endif //CLRS_QUICK_SORT_H
