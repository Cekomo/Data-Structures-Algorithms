#ifndef BINARYHEAP_H
#define BINARYHEAP_H

// #include "AlgorithmSortHeap.h" // not sure about this
#include <iostream>

using namespace std;

class BinaryHeap {
private: // for size and heap
	int size; // keeps the number of elements in the heap
	int capacity;
	int* heap;
	void percolateDown(int); // takes stated root (which was last index) and locates it's correct position
	// ^ private since stated in deleteMin method
public:
	BinaryHeap(int);
	
	void insert(int); // inserts a new number 
	int deleteMin(); // removes min element and returns
	int getMin();	// returns element (root) without deleting
	void swap(int, int);

	~BinaryHeap(); // remove from memory
};

#endif // !BINARYHEAP_H
