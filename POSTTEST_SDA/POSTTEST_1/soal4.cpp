#include <iostream>

using namespace std;


void tukarNilai(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}


void soalEmpat() {
    cout << "\n+--------------------------------------+\n";
    cout << "|     SOAL 4: Pointer pada Fungsi      |\n";
    cout << "+--------------------------------------+\n\n";
    
    int nilai1, nilai2;
    cout << " > Masukkan nilai pertama: ";
    cin >> nilai1;
    cout << " > Masukkan nilai kedua  : ";
    cin >> nilai2;

    cout << "\n== Sebelum Pertukaran ==\n";
    cout << "   Nilai pertama: " << nilai1 << '\n';
    cout << "   Nilai kedua  : " << nilai2 << '\n';

    tukarNilai(nilai1, nilai2);

    cout << "\n== Setelah Pertukaran ==\n";
    cout << "   Nilai pertama: " << nilai1 << '\n';
    cout << "   Nilai kedua  : " << nilai2 << '\n';
}

int main() {
    soalEmpat();
    return 0;
}