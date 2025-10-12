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

// Fungsi buat jalan-jalan di pohon pake cara pre-order.
// Urutannya: Root -> Kiri -> Kanan.
void preOrderTraversal(Node* root) {
    // Kalo nodenya udah null, stop rekursifnya.
    if (root == nullptr) {
        return;
    }

    // 1. Begitu datengin satu node, langsung kita proses (cetak) datanya.
    cout << root->data << " ";

    // 2. Baru deh kita jalan ke anak kirinya.
    preOrderTraversal(root->left);

    // 3. Kalo yang kiri udah beres, lanjut ke anak kanannya.
    preOrderTraversal(root->right);
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Pre-order traversal dari tree adalah: ";
    preOrderTraversal(root);
    cout << endl;
    return 0;
}