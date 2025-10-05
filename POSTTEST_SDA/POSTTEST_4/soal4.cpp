#include <iostream>
using namespace std;

// Node buat circular doubly linked list
struct Node {
    int data;   // data integer
    Node* next; // pointer ke node selanjutnya
    Node* prev; // pointer ke node sebelumnya
};

// Insert data ke list yang udah sorted
// head_ref bisa berubah kalo data baru lebih kecil dari head
void sortedInsert(Node *&head_ref, int data) {
    // bikin node baru
    Node* newNode = new Node{data, nullptr, nullptr};

    // Kasus 1: kalo list masih kosong
    if (head_ref == nullptr) {
        // sambung node ke dirinya sendiri (karena circular)
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode; // head tunjuk ke node baru
        return;
    }

    // cari node terakhir (tail)
    Node* tail = head_ref->prev;

    // Kasus 2: kalo data baru lebih kecil dari head
    if (data < head_ref->data) {
        // sambung node baru ke head dan tail
        newNode->next = head_ref;
        newNode->prev = tail;
        
        // update sambungan head dan tail ke node baru
        head_ref->prev = newNode;
        tail->next = newNode;
        
        // update head_ref ke node baru
        head_ref = newNode;
        return;
    }
    
    // Kasus 3: cari tempat buat insert data (tengah/akhir)
    Node* current = head_ref;
    
    // traversal selama belum balik ke head DAN 
    // node selanjutnya masih lebih kecil dari data
    while (current->next != head_ref && current->next->data < data) {
        current = current->next;
    }
    
    // insert node baru setelah current
    Node* nextNode = current->next;
    
    // sambung node baru
    newNode->next = nextNode;
    newNode->prev = current;
    
    // update sambungan node tetangga
    current->next = newNode;
    nextNode->prev = newNode;
}

// print semua data di list
void printList(Node *head_ref)
{
    // kalo list kosong
    if (head_ref == nullptr)
    {
        cout << "List kosong" << endl;
        return;
    }

    Node *current = head_ref;
    do
    {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);
    cout << endl;
}

// testing insert data
int main()
{
    Node *head = nullptr;

    cout << "--- Menyisipkan data ---" << endl;
    sortedInsert(head, 30); // List: 30
    printList(head);
    sortedInsert(head, 10); // List: 10 30
    printList(head);
    sortedInsert(head, 40); // List: 10 30 40
    printList(head);
    sortedInsert(head, 20); // List: 10 20 30 40
    printList(head);
    sortedInsert(head, 10); // Sisipkan duplikat: 10 10 20 30 40
    printList(head);
    sortedInsert(head, 50); // Sisipkan di akhir: 10 10 20 30 40 50
    printList(head);

    return 0;
}