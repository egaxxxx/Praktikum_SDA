#include <iostream>

using namespace std;

void tampilkanArray(int *arr, int size) {
    cout << "[ ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << (i == size - 1 ? "" : ", ");
    }
    cout << " ]\n";
}

void balikArray(int *arr, int size) {
    int awal = 0;
    int akhir = size - 1;
    while (awal < akhir) {
        int temp = arr[awal];
        arr[awal] = arr[akhir];
        arr[akhir] = temp;
        awal++;
        akhir--;
    }
}

void soalSatu() {
    cout << "\n+-----------------------------------------------+\n";
    cout << "|        SOAL 1: Array + Pointer (Balik Urutan) |\n";
    cout << "+-----------------------------------------------+\n\n";
    
    const int UKURAN = 7;
    int bilanganPrima[UKURAN] = {2, 3, 5, 7, 11, 13, 17};

    cout << "Array SEBELUM dibalik:\n";
    tampilkanArray(bilanganPrima, UKURAN);

    balikArray(bilanganPrima, UKURAN);

    cout << "\nArray SETELAH dibalik:\n";
    tampilkanArray(bilanganPrima, UKURAN);
}

int main() {
    soalSatu();
    return 0;
}