#include <iostream>
#include "test/test.h"


int main() {
    test(INSERTION_SORT);
    test(MERGE_SORT);
    test(HEAP_SORT);
    test(QUICK_SORT);
    return 0;
}