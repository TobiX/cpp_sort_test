
#include <iostream>

#ifdef BUILD_QT
#include <QVector>
#include <QtAlgorithms>
#define TEST_TYPE QVector<int>
#define SORT_FUNC qSort

#elif BUILD_STL
#include <vector>
#include <algorithm>
#define TEST_TYPE std::vector<int>
#define SORT_FUNC std::sort

#elif BUILD_EASTL
#include <EASTL/vector.h>
#include <EASTL/sort.h>
#include "eastlallocator.h"
#define TEST_TYPE eastl::vector<int>
#define SORT_FUNC eastl::sort

#else
#error What do you want?
#endif

bool slightly_broken_comparer(int a, int b) {
    std::cout << "C a: " << a << " b: " << b << std::endl;
    if (b == 17)
        return a < b;
    else
        return a > b;
}

int main(int argc, char *argv[])
{
    TEST_TYPE test;
    test.push_back(41);
    test.push_back(25);
    test.push_back( 7);
    test.push_back(17);
    test.push_back(34);
    test.push_back(58);
    test.push_back(94);
    test.push_back(23);
    test.push_back(14);
    test.push_back(46);

    for (TEST_TYPE::iterator it = test.begin(); it != test.end(); it++)
        std::cout << (*it) << " ";
    SORT_FUNC(test.begin(), test.end(), slightly_broken_comparer);
    std::cout << std::endl;

    SORT_FUNC(test.begin(), test.end(), slightly_broken_comparer);

    for (TEST_TYPE::iterator it = test.begin(); it != test.end(); it++)
        std::cout << (*it) << " ";
    std::cout << std::endl;

    return 0;
}

