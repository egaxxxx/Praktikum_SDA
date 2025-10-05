#include <iostream>
#include <string>
using namespace std;

// Node buat stack linked list
struct Node {
    char data;  // nyimpen karakter
    Node* next; // pointer ke node selanjutnya
};

// Push: nambah elemen ke stack
void push(Node*& top, char data) {
    // bikin node baru
    Node* newNode = new Node{data, top};
    // geser top ke node baru
    top = newNode;
}

// Pop: ambil elemen dari stack
char pop(Node*& top) {
    // kalo stack kosong, return null char
    if (top == nullptr) return '\0';
    
    // simpen node yang lagi di top
    Node* temp = top;
    // ambil data dari node itu
    char poppedValue = temp->data;
    // geser top ke node selanjutnya
    top = top->next;
    // hapus node yang udah diambil datanya
    delete temp;
    
    return poppedValue;
}

// fungsi buat reverse string pake stack
string reverseString(string s) {
    Node* stackTop = nullptr; // inisialisasi stack kosong
    string reversed = "";      // string hasil reverse

    // masukin semua karakter ke stack
    for (char c : s) {
        push(stackTop, c);
    }

    // ambil semua karakter dari stack (bakal kebalik urutannya)
    // dan masukin ke string reversed
    while (stackTop != nullptr) {
        reversed += pop(stackTop);
    }

    return reversed;
}

// fungsi main buat testing
int main() {
    string text = "Struktur Data";
    cout << "Teks asli: " << text << endl;
    cout << "Teks terbalik: " << reverseString(text) << endl; 
    
    string anotherText = "Algoritma";
    cout << "\nTeks asli: " << anotherText << endl;
    cout << "Teks terbalik: " << reverseString(anotherText) << endl; 
    
    return 0;
}