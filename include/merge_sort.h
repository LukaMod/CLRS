//
// Created by Luka on 2018/8/17.
//

#ifndef CLRS_MERGE_SORT_H
#define CLRS_MERGE_SORT_H

#include <functional>
#include <iterator>

template <class BidirectionalIt, class Compare>
void merge(
        BidirectionalIt first,
        BidirectionalIt mid,
        BidirectionalIt last,
        Compare compare
        ) {
    using value_type = typename std::iterator_traits<BidirectionalIt>::value_type;
    std::vector<value_type> left(first, mid);
    std::vector<value_type> right(mid, last);

    auto i = left.cbegin(), j = right.cbegin();
    auto l_end = left.cend(), r_end = right.cend();
    for (BidirectionalIt it = first; it != last; ++it) {
        if (i == l_end)
            *it = std::move(*j++);
        else if (j == r_end)
            *it = std::move(*i++);
        else
            *it = (compare(*i, *j) ? std::move(*i++) : std::move(*j++));
    }
}

template <class BidirectionalIt, class Compare = std::less<>>
void mergeSort(
        BidirectionalIt first,
        BidirectionalIt last,
        Compare compare = Compare()
        ) {
    auto size = std::distance(first, last);
    if (size > 1) {
        BidirectionalIt mid = first;
        std::advance(mid, size / 2);
        mergeSort(first, mid, compare);
        mergeSort(mid, last, compare);
        merge(first, mid, last, compare);
    }
}

#endif //CLRS_MERGE_SORT_H
