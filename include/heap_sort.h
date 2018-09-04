//
// Created by Luka on 2018/8/17.
//

#ifndef CLRS_HEAP_SORT_H
#define CLRS_HEAP_SORT_H

#include <iterator>
#include <functional>

template <class BidirectionalIt>
BidirectionalIt parent(BidirectionalIt first, BidirectionalIt i) {
    assert(i != first);
    BidirectionalIt ret = first;
    std::advance(ret, std::distance(first, i) / 2);
    return ret;
}

template <class BidirectionalIt>
BidirectionalIt left(BidirectionalIt first, BidirectionalIt i) {
    BidirectionalIt ret = i;
    std::advance(ret, std::distance(first, i) + 1);
    return ret;
}

template <class BidirectionalIt>
BidirectionalIt right(BidirectionalIt first, BidirectionalIt i) {
    BidirectionalIt ret = i;
    std::advance(ret, std::distance(first, i) + 2);
    return ret;
}

template <class BidirectionalIt, class Compare>
void maxHeapify(
        BidirectionalIt first,
        BidirectionalIt last,
        BidirectionalIt i,
        Compare compare
                ) {
    BidirectionalIt l = left(first, i), r = right(first, i);
    BidirectionalIt maxi = i;
    if (std::distance(l, last) > 0 && compare(*maxi, *l))
        maxi = l;
    if (std::distance(r, last) > 0 && compare(*maxi, *r))
        maxi = r;
    if (maxi != i) {
        std::swap(*maxi, *i);
        maxHeapify(first, last, maxi, compare);
    }
}

template <class BidirectionalIt, class Compare>
void buildMaxheap(
        BidirectionalIt first,
        BidirectionalIt last,
        Compare compare
        ) {
    auto size = std::distance(first, last);
    BidirectionalIt prev = std::prev(first);
    for (BidirectionalIt i = first + size / 2; i != prev; --i)
        maxHeapify(first, last, i, compare);
}

template <class BidirectionalIt, class Compare = std::less<>>
void heapSort(
        BidirectionalIt first,
        BidirectionalIt last,
        Compare compare = Compare()
        ) {
    if (std::distance(first, last) < 2)
        return;
    buildMaxheap(first, last, compare);
    BidirectionalIt i = last;
    for (--i; i != first; --i) {
        std::swap(*first, *i);
        maxHeapify(first, --last, first, compare);
    }
}

#endif //CLRS_HEAP_SORT_H
