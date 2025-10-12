#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}

// Fungsi buat nyari nilai paling kecil di BST.
int findMinValue(Node* root) {
    // Cek dulu, kalo pohonnya kosong, balikin -1 aja sebagai tanda.
    if (root == nullptr) {
        return -1;
    }

    Node* current = root;
    
    // Di BST, nilai terkecil itu pasti ada di paling kiri.
    // Jadi, kita geser ke kiri terus sampe mentok (anak kirinya null).
    while (current->left != nullptr) {
        current = current->left;
    }

    // Nah, node yang paling kiri mentok itu pasti yang paling kecil nilainya.
    return current->data;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);

    cout << "Nilai terkecil dalam tree adalah: " << findMinValue(root) << endl;
    return 0;
}