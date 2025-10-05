#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

/*
 * Fungsi ini menerima referensi ke pointer head.
 * Pointer head akan di-update setelah penukaran.
 */
void exchangeHeadAndTail(Node *&head_ref) {
    // Hanya berjalan jika ada 2 node atau lebih
    if (head_ref == nullptr || head_ref->next == head_ref) {
        return;
    }

    Node* head = head_ref;
    Node* tail = head_ref->prev;  // Tail adalah prev dari head

    // Kasus Khusus: Hanya 2 node (misal: 1 <-> 5)
    if (head->next == tail) {
        // Cukup tukar head_ref
        head_ref = tail;
        return;
    }

    // Kasus Normal: 3 node atau lebih (misal: 1 <-> 2 <-> 3 <-> 4 <-> 5)
    
    // 1. Simpan neighbor dari Head dan Tail
    Node* head_next = head->next; // Node '2'
    Node* tail_prev = tail->prev; // Node '4'

    // 2. Sambungkan Head lama (yang sekarang di akhir) ke neighbor Tail lama
    // Rantai baru: ... <-> tail_prev(4) <-> head(1) <-> tail(5) <-> ... (belum)
    head->prev = tail_prev;   // '1' prev menunjuk ke '4'
    tail_prev->next = head;   // '4' next menunjuk ke '1'

    // 3. Sambungkan Tail lama (yang sekarang di awal) ke neighbor Head lama
    // Rantai baru: ... <-> head(1) <-> tail(5) <-> head_next(2) <-> ...
    tail->next = head_next;   // '5' next menunjuk ke '2'
    head_next->prev = tail;   // '2' prev menunjuk ke '5'

    // 4. Perbaiki koneksi sirkular yang baru (antara Tail dan Head baru)
    // Tail baru (head lama) akan menunjuk ke Head baru (tail lama)
    head->next = tail;        // '1' next menunjuk ke '5'
    tail->prev = head;        // '5' prev menunjuk ke '1'
    
    // 5. Update head_ref ke Tail lama (yang sekarang menjadi Head baru)
    head_ref = tail;
}

void printList(Node *head_ref)
{
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

void insertEnd(Node *&head_ref, int data)
{
    Node *newNode = new Node{data, nullptr, nullptr};

    if (head_ref == nullptr)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }

    Node *tail = head_ref->prev;
    newNode->next = head_ref;
    newNode->prev = tail;
    head_ref->prev = newNode;
    tail->next = newNode;
}

int main()
{
    Node *head = nullptr;

    // Buat list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5); // Head=1, Tail=5

    cout << "List sebelum exchange: ";
    printList(head); // Output: 1 2 3 4 5

    exchangeHeadAndTail(head); // Head=5, Tail=1

    cout << "List setelah exchange head dan tail: ";
    // Expected output: 5 2 3 4 1
    printList(head);
    
    // Uji Kasus 2: List dengan 2 node
    Node *head2 = nullptr;
    insertEnd(head2, 10);
    insertEnd(head2, 20); // Head=10, Tail=20
    cout << "\nList 2 node sebelum exchange: ";
    printList(head2); // Output: 10 20
    exchangeHeadAndTail(head2);
    cout << "List 2 node setelah exchange: ";
    printList(head2); // Output: 20 10

    return 0;
}