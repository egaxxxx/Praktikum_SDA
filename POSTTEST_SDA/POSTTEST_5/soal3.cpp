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

// Fungsi buat nyari nilai paling gede di BST.
int findMaxValue(Node* root) {
    // Sama kayak tadi, kalo pohonnya kosong, balikin -1.
    if (root == nullptr) {
        return -1;
    }

    Node* current = root;

    // Kebalikannya nyari nilai terkecil, nilai terbesar itu pasti ada di paling kanan.
    // Jadi, kita geser ke kanan terus sampe mentok.
    while (current->right != nullptr) {
        current = current->right;
    }

    // Node paling kanan ini pasti yang nilainya paling gede.
    return current->data;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 80);

    cout << "Nilai terbesar dalam tree adalah: " << findMaxValue(root) << endl;
    return 0;
}