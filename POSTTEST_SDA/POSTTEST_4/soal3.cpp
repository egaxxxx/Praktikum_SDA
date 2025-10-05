#include <iostream>
#include <string>
using namespace std;

// node buat antrian printer
struct Node {
    string document; // nyimpen nama dokumen
    Node* next;      // pointer ke node selanjutnya
};

// Enqueue: nambah dokumen ke antrian (dari belakang)
void enqueue(Node*& front, Node*& rear, string document) {
    // bikin node baru buat dokumen
    Node* newNode = new Node{document, nullptr};

    // kalo antrian kosong
    if (front == nullptr) {
        front = newNode; // front dan rear tunjuk ke node yang sama
        rear = newNode;
    } 
    // kalo antrian udah ada isinya
    else {
        rear->next = newNode; // sambungkan node baru ke belakang
        rear = newNode;       // update rear ke node baru
    }
}

// Dequeue: ambil dokumen dari antrian (dari depan)
string dequeue(Node*& front, Node*& rear) {
    // kalo antrian kosong, return string kosong
    if (front == nullptr) return "";

    // simpen node depan yang mau dihapus
    Node* temp = front;
    string documentData = temp->document; // ambil nama dokumennya

    // geser front ke node selanjutnya
    front = front->next;

    // kalo front jadi null (antrian kosong), update rear juga
    if (front == nullptr) {
        rear = nullptr;
    }
    
    // hapus node depan yang udah diambil
    delete temp;
    return documentData;
}

// proses semua dokumen yang ada di antrian
void processAllDocuments(Node*& front, Node*& rear) {
    // terus ambil dokumen dari antrian sampe habis
    while (front != nullptr) {
        string processedDocument = dequeue(front, rear);
        cout << "Memproses: " << processedDocument << endl;
    }
}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;

    enqueue(front, rear, "Document1.pdf");
    enqueue(front, rear, "Report.docx");
    enqueue(front, rear, "Presentation.pptx");

    cout << "Memulai pemrosesan antrian printer:" << endl;
    processAllDocuments(front, rear);
    
    cout << "\nAntrian kosong." << endl;
    
    // coba tambah dokumen lagi setelah antrian kosong
    enqueue(front, rear, "Resume.pdf");
    cout << "Menambahkan dokumen baru. Memproses:" << endl;
    processAllDocuments(front, rear);

    return 0;
}