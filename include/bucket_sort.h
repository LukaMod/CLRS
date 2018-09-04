//
// Created by Luka on 2018/8/20.
//

#ifndef CLRS_BUCKET_SORT_H
#define CLRS_BUCKET_SORT_H

#include <functional>

#include "insertion_sort.h"

template <class BidirectionalIt, class Compare = std::less<>>
void bucketSort(
        BidirectionalIt first,
        BidirectionalIt last,
        Compare compare = Compare()) {

}

#endif //CLRS_BUCKET_SORT_H
