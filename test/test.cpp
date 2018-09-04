//
// Created by Luka on 2018/8/17.
//

#include "test.h"

#include <vector>
#include <random>
#include <iostream>
#include <iomanip>
#include <string>

#include "clrs_sort.h"

static std::vector<std::vector<int>> sample(size_t size) {
    assert(size >= 2);
    std::vector<std::vector<int>> ret;
    ret.push_back({});
    ret.push_back({1});

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis{0, 32};

    auto sz = size - 2;
    for (int i = 0; i != sz; ++i) {
        std::vector<int> elem;
        int size = dis(gen);
        for (int i = 0; i != size; ++i) {
            elem.push_back(dis(gen));
        }
        ret.push_back(elem);
    }
    return ret;
}

static bool is_sorted(const std::vector<int>& vec) {

    auto size = vec.size();

    if (size > 1) {
        for (int i = 1; i != size; ++i)
            if (vec[i - 1] > vec[i])
                return false;
    }

    return true;
}

void test(int sort) {
    auto test_sample = sample(50);
    int total = 0, success = 0;
    std::string s;
    std::vector<int> failed;

    for (auto i = 0; i != test_sample.size(); ++i) {
        auto sample = test_sample[i];
        switch (sort) {
            case INSERTION_SORT:
                insertionSort(sample.begin(), sample.end());
                s = "insertion_sort: ";
                break;
            case MERGE_SORT:
                mergeSort(sample.begin(), sample.end());
                s = "merge_sort: ";
                break;
            case HEAP_SORT:
                heapSort(sample.begin(), sample.end());
                s = "heap_sort: ";
                break;
            case QUICK_SORT:
                quickSort(sample.begin(), sample.end());
                s = "quick_sort: ";
                break;
        }
        if (is_sorted(sample))
            ++success;
        else
            failed.push_back(i);
        ++total;
    }
    std::cout << s << success << " success in " << total << " test: "
        << std::setiosflags(std::ios::fixed) << std::setprecision(2)
        << static_cast<double>(success) / total * 100 << "%\n";
    if (!failed.empty()) {
        std::cout << "### failed cases ###:\n";
        for (int index: failed) {
            std::cout << "case " << index << ": [";
            for (int val: test_sample[index])
                std::cout << " " << val;
            std::cout << " ]\n";
        }
    }
}