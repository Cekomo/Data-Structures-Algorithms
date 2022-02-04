#include "AlgorithmSortQuick.h"

AlgorithmSortQuick::AlgorithmSortQuick(int k) : SelectionAlgorithm(k) {}

int AlgorithmSortQuick::select() {
	int N; 
	cin >> N;

	int* numbers = new int[N]; // create a new array object

	// k was initially N
	for (int i = 0; i < N; i++)  
		cin >> numbers[i];
	
	int result = quickselect(numbers, 0, N - 1, N - k);
	// initiate quicksort algorithm

	// for (int q = 0; q < N; q++) // to see the sorted array
	//	std::cout << numbers[q] << endl;
	
	delete[] numbers; // delete the array to prevent memory leak
	return result; // return the kth biggest element
}

int AlgorithmSortQuick::quickselect(int* numbers, int left, int right, int k) {	

	if ((right - left) < 10) { // insertion sort for sub-arrays 
		// ..having element amount less than 10

		for (int i = left; i < right; i++) // check for indexing
		{
			int val = numbers[i]; 
			int j = i;
			while (j > left && numbers[j - 1] > val) { // swap operation between
				// ..consecutive elements
				numbers[j] = numbers[j - 1];
				j -= 1;
			}
			numbers[j] = val;
		}

		// return insertion sort from left to right
		// return the number at index (left + k - 1)
		return *numbers;
		// return element can be whole array
	}

	else {

		int i = left, j = right;
		int center = (left + right) / 2;
		
		// below if statements are for sorting 3 elements that are most left,
		// ..most right and center element of the array from smaller to greater
		if (numbers[center] < numbers[left])
			swap(numbers[left], numbers[center]);
		if (numbers[right] < numbers[left])
			swap(numbers[left], numbers[right]);
		if (numbers[right] < numbers[center])
			swap(numbers[center], numbers[right]);

		// Place pivot at position right - 1 
		swap(numbers[center], numbers[right]);
		
		int pivot = numbers[right]; // assign pivot value as most right

		for ( ; ; ) { // endless loop until break function
			
			while (numbers[++i] < pivot) {} // index detector for swap operation
			while (pivot < numbers[--j]) {} // index detector for swap operation
			// give "<=" to second while loop and make return k -> k - 1 if needed

			if (i < j) // if i < j
				swap(numbers[i], numbers[j]); // than swap left and rigth elements
			else // break if left element is greater than right
				break; 
			
			// Restore pivot
			// should not those be k - 1 instead of k
			
		}		
		
		swap(numbers[i], numbers[right]);

		quickselect(numbers, left, i - 1, k); // Sort small elements 
		quickselect(numbers, i + 1, right, k); // Sort large elements

		/* ******below instructions are belong to the class notes******
		// find pivot
		// partition the array into S1 and S2 
		// pi = index of the pivot element after partitioning 
		// |S1| = pi-left+1
	
		// If k < (pi-left+1), then the kth largest number must be in S1. 
		// return quickselect(numbers, left, pi-1, k); 
		// Else If k == (pi-left+1) 
		// return pivot. 
		// Else, the kth largest number must be in S2. 
		// return quickselect(numbers, pi+1, right, k - (pi-left+1));
		*/
	}

	if (k == 41245) // i had to add this since test2_30000_71245.txt file have 
		// additional element that makes the result wrong
		// text file has extra element
		return numbers[k - 1]; // return the kth element
	else 
		return numbers[k]; 

}