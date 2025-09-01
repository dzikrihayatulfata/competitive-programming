#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[100]; // asumsi maksimal 100 angka
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 1. Buang duplikat
    int unique[100]; // array untuk angka unik
    int uniqueCount = 0;

    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;
        
        for (int j = 0; j < uniqueCount; j++) {
            if (arr[i] == unique[j]) {
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate) {
            unique[uniqueCount] = arr[i];
            uniqueCount++;
        }
    }

    // 2. Urutkan hasilnya (pakai bubble sort)

    
    for (int i = 0; i < uniqueCount - 1; i++) {
        for (int j = 0; j < uniqueCount - i -1 ; j++) {
            if (unique[j] > unique[j + 1]) {
                // tukar
                int temp = unique[j];
                unique[j] = unique[j + 1];
                unique[j + 1] = temp;
            }
        }
    }

    // 3. Tampilkan hasil
    for (int i = 0; i < uniqueCount; i++) {
        // cout << unique[i] << " ";
    }
    cout << endl;

    return 0;
}
