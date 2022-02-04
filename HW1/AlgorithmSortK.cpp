#include "AlgorithmSortK.h"
#include <string>
using namespace std;
AlgorithmSortK::AlgorithmSortK(int k) : SelectionAlgorithm(k) {
}
int AlgorithmSortK::select() {
    int* pNums = 0; // pNums'ı pointer olarak atayıp null olarak dönmesi için 0 değerini verdik
    int n;
    cin >> n;
    int until_k = this->k; // this variable is initialized due to the adjusted range of the array
    // ^ bu değişken gereksiz
	pNums = new int[until_k]; // k'ya kadar olacak değerleri sıralamak için array
    for (int i = 1; i < k; i++)
        cin >> pNums[i]; // arraydeki i'inci değerlere teker teker ulaşmak için
	//	 ^ bu for loopu silip 21. satıra 14. satır uygulanabilir
	
    int key, j;
    for (int i = 1; i < until_k; i++) {
        key = pNums[i]; // i'inci pNums üyesini taşıyan değişken
		// ^ bu değişkeni silebilirdim
		// cin >> pNums[i]; buraya gelebilir
        j = i; // j adında yeni bir değişken atadık, i değerini değiştirmemesi için, nested loop
        while (j > 0 && key > pNums[j - 1]) { // pnums[i], pnums[j-1]'den büyükse pnums[j]'yi bir önceki member ile değiştir
            // while döngüsü her i'inci değer için j sıfır olana kadar devam eder
			pNums[j] = pNums[j - 1];
            j--;
        }
        pNums[j] = key; // sonuncu member için pNums[j], pNums[i] ile değiştilir
    }
    for (int i = 1; i <= n - k; i++) {
        int number;
        cin >> number; // sonraki elementi number olarak almak için cin statement
        if (number > pNums[until_k - 1]) { // sonraki element arraydeki k'inci elementten büyükse 
			// ..k'inci elementi number değişkenine eşitle
            pNums[until_k - 1] = number;
            int key, j;
            for (int i = until_k - 1; i < until_k; i++) {
                key = pNums[i]; // key değişkenini until_k'den bir önceki elemente eşitledik
                // ^ gereksiz
				j = i;
                while (j >= 0 && key > pNums[j - 1]) { // pNums[i], pNums[j-1]'den büyükse 
					// ..j sıfır olana dek pNums[j] elementini bir önceki elemente eşitle
                    pNums[j] = pNums[j - 1];
                    j--;
                }
                pNums[j] = key; // sonuncu member için pNums[j], pNums[i] ile değiştilir
            }
        }
    }
    int biggest_kth = pNums[until_k - 1]; // array içindeki k'inci değeri değişken olarak atadım
    delete[] pNums; // işlem bitince memory'deki pNums arrayini sil
    pNums = 0; // pNums'ı 0 a eşitleyerek memory'e geçersiz atama olmasını engelledim
    return biggest_kth;
}