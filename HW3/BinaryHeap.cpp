#include "BinaryHeap.h"

BinaryHeap::BinaryHeap(int capacity) {
	this->capacity = capacity; // why needed?
	
	heap = new int[capacity + 1];
	size = 0;
}

void BinaryHeap::insert(int element) { 
	if (capacity > size) {
		// percolate up
		int depth = ++size;
		heap[size] = element; // assign last node as element
		for (; depth > 1 && element < heap[depth / 2]; depth /= 2) // if child is smaller than parent
			swap(depth, depth / 2); // child is replaced with it's parent

		heap[depth] = element; // replace the last node with ?element?
		// remove this and try
	}
}


int BinaryHeap::deleteMin() {
	// state heap as an array
	if (size >= 1) {
		int lastLeaf = heap[size]; // get the last parameter

		heap[1] = lastLeaf; // replace root with last element
		heap[size] = 0; // delete the last element on the heap

		size = size - 1; // decrease size of heap by 1 
		percolateDown(1); // heapify the root 
		
	}
	return *heap; // not sure about return object
}

int BinaryHeap::getMin() {
	if (size < 1) // if the size is less than 1, return error
		return -1; 
	else { // else, return root's value
		return heap[1];
	}	
}

void BinaryHeap::percolateDown(int hole) {

	int root = hole;
	int left = 2 * hole; // left node
	int right = 2 * hole + 1; // right node

	if (left <= size && heap[hole] < heap[left]) { // checks if left child is greater than parent
		if (right <= size && heap[hole] < heap[right]) { // if right is grater than parent
			return; // do nothing
		}
		if (right <= size) { // if right is smaller than parent
			swap(hole, right); // swap child and parent
			percolateDown(right); // make the function recursive
		}
		return;
	}

	if (left <= size) { // checks if index of the left node is valid
		if (right <= size && heap[right] < heap[left]) { // if right child is smaller than left child
			swap(hole, right); // swap parent with right child
			percolateDown(right); // make it recursive
			return;
		}
		// if left is smaller than right child
		swap(hole, left); // swap parent and left
		percolateDown(left); // make it recursive
		return;
	}

	// below code was with above code
	if (right <= size) { // checks if index of the right node is valid
		if (heap[right] < heap[hole]) { // if right child is smaller than parent
			swap(hole, right); // swap parent with right child
			percolateDown(right); // make it recursive
		}
		return;
	}
	
	//-----------------------------------------------------------

	//if (heap[left] <= heap[right] && left <= size && right <= size) {
	//	if (heap[left] < heap[root]) {
	//		swap(root, left); // swap the parent with it's right child
	//		percolateDown(left); // recursively continue
	//	}

	//	return;
	//}
	//if (heap[right] < heap[left] && right <= size && left <= size) {
	//	if (heap[right] < heap[root]) {
	//		swap(root, right); // swap the parent with it's right child
	//		percolateDown(right); // recursively continue
	//	}

	//	return;
	//}
}

void BinaryHeap::swap(int i, int j) {
	int temp = heap[i];; // temp variable to swap operation 
	
	heap[i] = heap[j];
	heap[j] = temp;
}

BinaryHeap::~BinaryHeap() { // deconstructor to delete binary heap
	delete[] heap;
}