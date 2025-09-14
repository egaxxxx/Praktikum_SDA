#include <iostream>
#include <iomanip>

using namespace std;


void soalDua() {
    cout << "\n+--------------------------------------+\n";
    cout << "|          SOAL 2: Matriks 3x3         |\n";
    cout << "+--------------------------------------+\n\n";
    
    int matriks[3][3];
    int jumlah = 0;

    cout << "Masukkan elemen untuk matriks 3x3:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " > Masukkan elemen baris " << i << " kolom " << j << ": ";
            cin >> matriks[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < 3; j++) {
                jumlah += matriks[i][j];
            }
        }
    }

    cout << "\nMatriks yang Anda masukkan:\n";
    cout << "+-------+-------+-------+\n";
    for (int i = 0; i < 3; i++) {
        cout << "|";
        for (int j = 0; j < 3; j++) {
            cout << setw(6) << matriks[i][j] << " |";
        }
        cout << "\n+-------+-------+-------+\n";
    }

    cout << "\nJumlah elemen pada baris genap (baris 0 dan 2) adalah: " << jumlah << '\n';
}

int main() {
    soalDua();
    return 0;
}