#include <ctime>
#include "TestBed.h"

using namespace std;

TestBed::TestBed() {

}


void TestBed::setAlgorithm(int type, int k) {
    if (type == 1) {
        algorithm = new AlgorithmSortAll(k); 
        cout << "the array sortAll is created" << endl;
    }
    else if (type == 2) {
        algorithm = new AlgorithmSortK(k);
        cout << "the array sortK is created" << endl;
    }
    else if (type == 3) {
        algorithm = new AlgorithmSortHeap(k); 
        cout << "the array sortHeap is created" << endl;
    }
}


void TestBed::execute() {
    // Time stamp before the computations
    clock_t start = clock();

    /* Computations to be measured */
    int outcome = algorithm->select();

    // Time stamp after the computations
    clock_t end = clock();
    double cpu_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    cout << "Result: " << outcome << endl;
    cout << "Duration(sec): " << cpu_time << endl;
}


TestBed::~TestBed() {
    delete algorithm; // check if delete[] is valid
    // cout << "the array is deleted" << endl;
}
