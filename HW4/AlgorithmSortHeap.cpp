#include "AlgorithmSortHeap.h"
#include "BinaryHeap.h"

using namespace std;

AlgorithmSortHeap::AlgorithmSortHeap(int k) : SelectionAlgorithm(k) {
	this->k = k;
}

int AlgorithmSortHeap::select() {
	BinaryHeap heap(k);

	int element = 0;
	cin >> element; // returns as third number in the txt file wich is size of an array

	int insertElement = 0;
	int compareElement = 0;

	for (int i = 0; i < k; i++) { // inserts value received from text file
		cin >> insertElement;
		heap.insert(insertElement);
	}

	for (int i = k; i < element; i++) {
		cin >> compareElement;
		if (compareElement < heap.getMin()) {}
		else {
			heap.deleteMin();
			heap.insert(compareElement);
		}
	}

	return heap.getMin();
}

