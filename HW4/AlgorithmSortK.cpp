#include "AlgorithmSortK.h"

AlgorithmSortK::AlgorithmSortK(int k) : SelectionAlgorithm(k) {}

int AlgorithmSortK::select() {
    int *pNums = 0;
    int n;
    cin >> n;

    int until_k = this->k; // this variable is initialized due to the adjusted range of the array
    pNums = new int[until_k];

    for (int i = 0; i < until_k; i++)
        cin >> pNums[i];

    int key, j;
    for (int i = 1; i < until_k; i++) {
        key = pNums[i];
        j = i;

        while (j > 0 && key > pNums[j - 1]) {
            pNums[j] = pNums[j - 1];
            j--;
        }
        pNums[j] = key;
    }

    for (int i = 1; i <= n - k; i++) {
        int number;
        cin >> number;

        if (number > pNums[until_k - 1]) {
            pNums[until_k - 1] = number;

            int key, j;
            for (int i = until_k - 1; i < until_k; i++) {
                key = pNums[i];
                j = i;

                while (j > 0 && key > pNums[j - 1]) {
                    pNums[j] = pNums[j - 1];
                    j--;
                }
                pNums[j] = key;
            }
        }
    }

    int biggest_kth = pNums[until_k - 1];

    delete[] pNums;
    pNums = 0;
    return biggest_kth;
}
