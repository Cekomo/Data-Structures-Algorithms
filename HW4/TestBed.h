#include "SelectionAlgorithm.h"
#include "AlgorithmSortAll.h"
#include "AlgorithmSortK.h"
#include "AlgorithmSortHeap.h"
#include "AlgorithmSortQuick.h"

class TestBed {
private:
    SelectionAlgorithm* algorithm; // try if it is okay to use as public
public:
    TestBed();
    void execute();
    void setAlgorithm(int, int);
    ~TestBed(); 
};

