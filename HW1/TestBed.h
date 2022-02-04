#include "SelectionAlgorithm.h"

class TestBed {

private:
    SelectionAlgorithm* algorithm; // try if it is okay to use as public
public:
    TestBed();
    void execute();
    void setAlgorithm(int, int);
    ~TestBed(); 
};
