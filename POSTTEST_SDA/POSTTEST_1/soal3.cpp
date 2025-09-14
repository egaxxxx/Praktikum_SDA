#include <iostream>
#include <string>

using namespace std;


struct Mahasiswa {
    string nama;
    string nim;
    double ipk;
};

void soalTiga() {
    cout << "\n+--------------------------------------+\n";
    cout << "|        SOAL 3: Struct + Array        |\n";
    cout << "+--------------------------------------+\n\n";
    
    const int JUMLAH_MAHASISWA = 4;
    Mahasiswa daftarMahasiswa[JUMLAH_MAHASISWA];

    for (int i = 0; i < JUMLAH_MAHASISWA; i++) {
        cout << "\nMasukkan data untuk Mahasiswa ke-" << i + 1 << ":\n";
        cout << " > Nama: ";
        if (i > 0) {
           cin.ignore();
        }
        getline(cin, daftarMahasiswa[i].nama);
        
        cout << " > NIM : ";
        cin >> daftarMahasiswa[i].nim;
        
        cout << " > IPK : ";
        cin >> daftarMahasiswa[i].ipk;
    }

    for (int i = 0; i < JUMLAH_MAHASISWA - 1; i++) {
        for (int j = 0; j < JUMLAH_MAHASISWA - i - 1; j++) {
            if (daftarMahasiswa[j].ipk > daftarMahasiswa[j + 1].ipk) {
                Mahasiswa temp = daftarMahasiswa[j];
                daftarMahasiswa[j] = daftarMahasiswa[j + 1];
                daftarMahasiswa[j + 1] = temp;
            }
        }
    }

    cout << "\n--- Data Mahasiswa Berdasarkan IPK (Ascending) ---\n";
    cout << "No\t| Nama Mahasiswa\t\t| NIM\t\t\t| IPK\n";
    cout << "--------------------------------------------------------------------------\n";
    
    for (int i = 0; i < JUMLAH_MAHASISWA; i++) {
        cout << i + 1 << "\t| " 
             << daftarMahasiswa[i].nama << "\t\t| " 
             << daftarMahasiswa[i].nim << "\t\t| " 
             << daftarMahasiswa[i].ipk << endl;
    }
}

int main() {
    soalTiga();
    return 0;
}