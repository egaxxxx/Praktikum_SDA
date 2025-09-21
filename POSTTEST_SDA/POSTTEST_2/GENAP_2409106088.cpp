#include <iostream>
#include <cstdlib>   

using namespace std;

const int MAX_KODE = 20;
const int MAX_TUJUAN = 50;
const int MAX_STATUS = 50;
const int INT_BUFFER_SIZE = 12; 
const int INPUT_BUFFER_MAX = 4096; 

int my_strlen(const char* str) {
    int len = 0;
    while (str[len] != '\0') { len++; }
    return len;
}

void my_strcpy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void my_strcat(char* dest, const char* src) {
    int dest_len = my_strlen(dest);
    int i = 0;
    while (src[i] != '\0') {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
}

int my_strcmp(const char* s1, const char* s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

void reverse_str(char* str) {
    int start = 0;
    int end = my_strlen(str) - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void my_itoa(int num, char* buffer) {
    int i = 0;
    bool isNegative = false;
    if (num == 0) {
        buffer[i++] = '0';
        buffer[i] = '\0';
        return;
    }
    if (num < 0) {
        isNegative = true;
        num = -num;
    }
    while (num != 0) {
        buffer[i++] = (num % 10) + '0';
        num = num / 10;
    }
    if (isNegative) {
        buffer[i++] = '-';
    }
    buffer[i] = '\0';
    reverse_str(buffer);
}

struct JadwalPenerbangan {
    char kodePenerbangan[MAX_KODE];
    char tujuan[MAX_TUJUAN];
    char status[MAX_STATUS];
    JadwalPenerbangan* next; 
};

JadwalPenerbangan* head = NULL;
char baseKode[MAX_KODE];
int sisipPos;
int counterJadwal = 0;

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void clearInputBuffer() {
    cin.ignore(INPUT_BUFFER_MAX, '\n');
}

void buatKodeUnik(char* outputKode) {
    if (counterJadwal == 0) {
        my_strcpy(outputKode, baseKode);
    } else {
        my_strcpy(outputKode, baseKode);
        my_strcat(outputKode, "-");
        char numBuffer[INT_BUFFER_SIZE];
        my_itoa(counterJadwal, numBuffer);
        my_strcat(outputKode, numBuffer);
    }
}

void tambahJadwal() {
    JadwalPenerbangan* nodeBaru = new JadwalPenerbangan();
    cout << "\n--- Tambah Jadwal Baru (di Akhir) ---\n";
    cout << "Masukkan Tujuan: ";
    cin.getline(nodeBaru->tujuan, MAX_TUJUAN);
    cout << "Masukkan Status (e.g., Tepat Waktu, Terlambat): ";
    cin.getline(nodeBaru->status, MAX_STATUS);

    buatKodeUnik(nodeBaru->kodePenerbangan);
    nodeBaru->next = NULL;
    counterJadwal++;

    if (head == NULL) { head = nodeBaru; } 
    else {
        JadwalPenerbangan* temp = head;
        while (temp->next != NULL) { temp = temp->next; }
        temp->next = nodeBaru;
    }
    cout << "\n>> Jadwal dengan kode " << nodeBaru->kodePenerbangan << " berhasil ditambahkan!\n";
}

int hitungNode() {
    int count = 0;
    JadwalPenerbangan* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void sisipkanJadwal() {
    int jumlahNodeSekarang = hitungNode();
    
    if (jumlahNodeSekarang < sisipPos - 1) {
        cout << "\n>> GAGAL: Tidak bisa menyisipkan jadwal di posisi " << sisipPos << ".\n";
        cout << ">> Jumlah jadwal saat ini hanya " << jumlahNodeSekarang << ", butuh minimal " << sisipPos - 1 << " jadwal.\n";
        return; 
    }

    JadwalPenerbangan* nodeBaru = new JadwalPenerbangan();
    cout << "\n--- Sisipkan Jadwal Baru (di Posisi " << sisipPos << ") ---\n";
    cout << "Masukkan Tujuan: ";
    cin.getline(nodeBaru->tujuan, MAX_TUJUAN);
    cout << "Masukkan Status (e.g., Tepat Waktu, Terlambat): ";
    cin.getline(nodeBaru->status, MAX_STATUS);
    
    buatKodeUnik(nodeBaru->kodePenerbangan);
    counterJadwal++;

    JadwalPenerbangan* temp = head;
    for (int pos = 1; pos < sisipPos - 1; pos++) {
        temp = temp->next;
    }
    
    nodeBaru->next = temp->next;
    temp->next = nodeBaru;
    
    cout << "\n>> Jadwal dengan kode " << nodeBaru->kodePenerbangan << " berhasil disisipkan pada posisi " << sisipPos << ".\n";
}

void hapusJadwalAwal() {
    if (head == NULL) { cout << "\n>> Tidak ada jadwal untuk dihapus, list kosong.\n"; return; }
    JadwalPenerbangan* temp = head;
    char kodeHapus[MAX_KODE];
    my_strcpy(kodeHapus, temp->kodePenerbangan);
    head = head->next;
    delete temp;
    cout << "\n>> Jadwal paling awal dengan kode " << kodeHapus << " berhasil dihapus.\n";
}

void hapusJadwalAkhir() {
    if (head == NULL) { cout << "\n>> Tidak ada jadwal untuk dihapus, list kosong.\n"; return; }
    JadwalPenerbangan* temp = head;
    char kodeHapus[MAX_KODE];
    if (temp->next == NULL) {
        my_strcpy(kodeHapus, temp->kodePenerbangan);
        head = NULL;
        delete temp;
    } else {
        JadwalPenerbangan* prev = NULL;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        my_strcpy(kodeHapus, temp->kodePenerbangan);
        prev->next = NULL;
        delete temp;
    }
    cout << "\n>> Jadwal paling akhir dengan kode " << kodeHapus << " berhasil dihapus.\n";
}

void updateStatus() {
    if (head == NULL) { 
        cout << "\n>> List jadwal kosong, tidak ada yang bisa di-update.\n"; 
        return; 
    }

    cout << "\n--- Update Status Penerbangan ---\n";
    cout << "Daftar Kode Penerbangan yang Tersedia:\n";
    JadwalPenerbangan* temp = head;
    while(temp != NULL) {
        cout << "- " << temp->kodePenerbangan << '\n';
        temp = temp->next;
    }
    cout << "----------------------------------------\n";

    char kodeCari[MAX_KODE];
    cout << "Masukkan Kode Penerbangan yang statusnya ingin diubah: ";
    cin.getline(kodeCari, MAX_KODE);

    JadwalPenerbangan* current = head;
    bool ditemukan = false;
    while (current != NULL) {
        if (my_strcmp(current->kodePenerbangan, kodeCari) == 0) {
            ditemukan = true;
            cout << "Jadwal ditemukan!\n";
            cout << "Status saat ini: " << current->status << '\n';
            cout << "Masukkan Status Baru: ";
            cin.getline(current->status, MAX_STATUS);
            cout << "\n>> Status untuk kode " << kodeCari << " berhasil di-update.\n";
            break; 
        }
        current = current->next;
    }
    if (!ditemukan) { cout << "\n>> Jadwal dengan kode " << kodeCari << " tidak ditemukan.\n"; }
}

void cariJadwal() {
    if (head == NULL) { 
        cout << "\n>> List jadwal kosong.\n"; 
        return; 
    }

    cout << "\n--- Cari Jadwal Penerbangan ---\n";
    cout << "Daftar Kode Penerbangan yang Tersedia:\n";
    JadwalPenerbangan* temp = head;
    while(temp != NULL) {
        cout << "- " << temp->kodePenerbangan << '\n';
        temp = temp->next;
    }
    cout << "----------------------------------------\n";

    char kodeCari[MAX_KODE];
    cout << "Masukkan Kode Penerbangan yang ingin dicari: ";
    cin.getline(kodeCari, MAX_KODE);

    JadwalPenerbangan* current = head;
    bool ditemukan = false;
    while (current != NULL) {
        if (my_strcmp(current->kodePenerbangan, kodeCari) == 0) {
            ditemukan = true;
            cout << "\n>> Jadwal Ditemukan <<\n";
            cout << "Kode   : " << current->kodePenerbangan << '\n';
            cout << "Tujuan : " << current->tujuan << '\n';
            cout << "Status : " << current->status << '\n';
            break;
        }
        current = current->next;
    }
    if (!ditemukan) { cout << "\n>> Jadwal dengan kode " << kodeCari << " tidak ditemukan.\n"; }
}

void printWithPadding(const char* text, int width) {
    int len = my_strlen(text);
    cout << text;
    for (int i = 0; i < width - len; ++i) {
        cout << ' ';
    }
}

void tampilkanSemuaJadwal() {
    clearScreen();
    cout << "\n===================================================================\n";
    cout << "                     DAFTAR JADWAL PENERBANGAN                     \n";
    cout << "===================================================================\n";

    if (head == NULL) {
        cout << "                 >> Tidak ada jadwal tersedia <<                  \n";
    } else {
        printWithPadding("No.", 5);
        printWithPadding("KODE", 15);
        printWithPadding("TUJUAN", 25);
        printWithPadding("STATUS", 20);
        cout << '\n';
        cout << "-------------------------------------------------------------------\n";

        JadwalPenerbangan* temp = head;
        int no = 1;
        while (temp != NULL) {
            char noStr[INT_BUFFER_SIZE];
            my_itoa(no, noStr);
            my_strcat(noStr, ".");
            
            printWithPadding(noStr, 5);
            printWithPadding(temp->kodePenerbangan, 15);
            printWithPadding(temp->tujuan, 25);
            printWithPadding(temp->status, 20);
            cout << '\n';
            
            temp = temp->next;
            no++;
        }
    }
    cout << "===================================================================\n";
}

void hitungJumlahJadwal() {
    cout << "\n>> Jumlah total jadwal penerbangan saat ini adalah: " << hitungNode() << " jadwal.\n";
}

int main() {
    const char* nim = "088";

    if (my_strlen(nim) < 3) { cout << "NIM tidak valid. Program berhenti.\n"; return 1; }
    
    const char* lastThreeDigits = nim + (my_strlen(nim) - 3);
    my_strcpy(baseKode, "JT-");
    my_strcat(baseKode, lastThreeDigits);

    int digitTerakhir = nim[my_strlen(nim) - 1] - '0'; 
    sisipPos = (digitTerakhir == 0) ? 2 : digitTerakhir + 1;

    int pilihan;
    do {
        clearScreen();
        cout << "+-------------------------------------------+\n";
        cout << "|           FLIGHT SCHEDULE SYSTEM          |\n";
        cout << "|           Ega Clearesta Hananta           |\n";
        cout << "|                     088                   |\n";
        cout << "+-------------------------------------------+\n";
        cout << "| Menu Utama:                               |\n";
        cout << "+-------------------------------------------+\n";
        cout << "| 1. Tambah Jadwal (di Akhir)               |\n";
        cout << "| 2. Sisipkan Jadwal (di Posisi 9)          |\n";
        cout << "| 3. Update Status Penerbangan              |\n";
        cout << "| 4. Cari Jadwal Penerbangan                |\n";
        cout << "| 5. Hapus Jadwal Paling Awal               |\n";
        cout << "| 6. Hapus Jadwal Paling Akhir              |\n";
        cout << "| 7. Tampilkan Semua Jadwal                 |\n";
        cout << "| 8. Tampilkan Jumlah Jadwal                |\n";
        cout << "| 0. Keluar                                 |\n";
        cout << "+-------------------------------------------+\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        
        if (cin.fail()) {
            cout << "\nInput tidak valid. Harap masukkan angka.\n";
            cin.clear(); 
            clearInputBuffer(); 
            pilihan = -1; 
            continue;
        }
        
        clearInputBuffer(); 

        switch (pilihan) {
            case 1: tambahJadwal(); break;
            case 2: sisipkanJadwal(); break;
            case 3: updateStatus(); break;
            case 4: cariJadwal(); break;
            case 5: hapusJadwalAwal(); break;
            case 6: hapusJadwalAkhir(); break;
            case 7: tampilkanSemuaJadwal(); break;
            case 8: hitungJumlahJadwal(); break;
            case 0: cout << "\nTerima kasih telah menggunakan sistem ini. Sampai jumpa! 👋\n"; break;
            default: cout << "\nPilihan tidak valid. Silakan coba lagi.\n";
        }

        if (pilihan != 0) {
            cout << "\nTekan Enter untuk kembali ke menu...";
            cin.get();
        }
    } while (pilihan != 0);

    return 0;
}