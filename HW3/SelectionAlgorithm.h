#ifndef SELECTION_H 
#define SELECTION_H
#include <iostream>

// #include "AlgorithmSortAll.h"
// #include "AlgorithmSortK.h"

class SelectionAlgorithm {
protected:
    int k;
public:
    virtual int select() = 0;
    // ^ it is virtual since it is implemented by subclasses of SelectionAlgorithm
    SelectionAlgorithm(int);
};

#endif // SELECTION_H
