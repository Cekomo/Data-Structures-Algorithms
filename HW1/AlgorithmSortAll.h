#ifndef ALGORITHMSORTALL_H
#define ALGORITHMSORTALL_H
#include <iostream>
#include "SelectionAlgorithm.h"

using namespace std;


class AlgorithmSortAll : public SelectionAlgorithm {

public:
    int select();
    AlgorithmSortAll(int);
};

#endif // ALGORITHMSORTALL_H

