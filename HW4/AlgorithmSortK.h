#ifndef ALGORITHMSORTK_H
#define ALGORITHMSORTK_H

#include <iostream>
#include "SelectionAlgorithm.h"
using namespace std;

class AlgorithmSortK : public SelectionAlgorithm {
public:
    int select();
    AlgorithmSortK(int);
};

#endif // ALGORITHMSORTK_H
