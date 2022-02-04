#include "AlgorithmSortAll.h"

AlgorithmSortAll::AlgorithmSortAll(int k) : SelectionAlgorithm(k) {

}

int AlgorithmSortAll::select() {
    int* pNums = 0; // Define pNums as a pointer to int, initialize to null
    int n; // Define n for keeping the size needed for the array
    cin >> n; // Read in the size

    pNums = new int[n]; // Allocate n ints and save the pointer in pNums

    for (int i = 0; i < n; i++)
        cin >> pNums[i]; // Takes input value and inserts to the array

    int key, j;
    for (int i = 1; i < n; i++) {
        key = pNums[i]; // Define a variable that represents kth ith member
        j = i - 1; // i-1 = i

        // Below is the part for sorting the array
        while (j > 0 && key > pNums[j]) { // This part may cause a problem (pNums[j] > keys)
            pNums[j + 1] = pNums[j]; // j+1 = j, j = j-1
            j = j - 1;
        }
        pNums[j + 1] = key; // j + 1 = j
    }

    int biggest_kth = pNums[(this->k) - 1]; // can be without -1
    //   ^ takes the kth value (-1 is due to the range issue of an array)

    delete[] pNums; // When done, free the memory pointed to by pNums
    pNums = 0; // Clear pNums to prevent using invalid memory reference

    return biggest_kth;
}