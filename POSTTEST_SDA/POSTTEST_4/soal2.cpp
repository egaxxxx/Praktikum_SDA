#include <iostream>
#include <string>
using namespace std;

// struktur node stack
struct Node {
    char data;  // simpan karakter kurung
    Node* next; // pointer ke node selanjutnya
};

// Push: nambah kurung buka ke stack
void push(Node*& top, char data) {
    Node* newNode = new Node{data, top};
    top = newNode;
}

// Pop: ambil kurung dari stack
char pop(Node*& top) {
    // cek dulu stack kosong apa nggak
    if (top == nullptr) return '\0'; 
    
    Node* temp = top;
    char poppedValue = temp->data;
    top = top->next;
    delete temp;
    
    return poppedValue;
}

// bantu cek pasangan kurung
bool isMatchingPair(char char1, char char2) {
    if (char1 == '(' && char2 == ')')
        return true;
    else if (char1 == '{' && char2 == '}')
        return true;
    else if (char1 == '[' && char2 == ']')
        return true;
    else
        return false;
}

// cek apakah kurung seimbang
bool areBracketsBalanced(string expr) {
    Node* stackTop = nullptr; 

    for (char c : expr) {
        // kalo ketemu kurung buka, push ke stack
        if (c == '(' || c == '{' || c == '[') {
            push(stackTop, c);
        }

        // kalo ketemu kurung tutup, cek matching
        if (c == ')' || c == '}' || c == ']') {
            // kalo stack kosong berarti nggak ada pasangannya
            if (stackTop == nullptr) {
                return false;
            }

            // ambil kurung terakhir dari stack
            char poppedChar = pop(stackTop);
            // cek apakah cocok sama kurung yang sekarang
            if (!isMatchingPair(poppedChar, c)) {
                return false;
            }
        }
    }
    
    // kalo stack kosong berarti semua kurung sudah seimbang
    return (stackTop == nullptr);
}

// testing fungsi
int main() {
    string expr1 = "{[()]}";
    cout << expr1 << " -> " << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") << endl;
    
    string expr2 = "{[(])}";
    cout << expr2 << " -> " << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") << endl;

    string expr3 = "([{}])";
    cout << expr3 << " -> " << (areBracketsBalanced(expr3) ? "Seimbang" : "Tidak Seimbang") << endl;

    string expr4 = "([)]";
    cout << expr4 << " -> " << (areBracketsBalanced(expr4) ? "Seimbang" : "Tidak Seimbang") << endl;

    string expr5 = "{{[";
    cout << expr5 << " -> " << (areBracketsBalanced(expr5) ? "Seimbang" : "Tidak Seimbang") << endl;
    
    string expr6 = "}}";
    cout << expr6 << " -> " << (areBracketsBalanced(expr6) ? "Seimbang" : "Tidak Seimbang") << endl;

    return 0;
}