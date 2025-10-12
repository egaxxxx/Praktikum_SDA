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

// Fungsi buat jalan-jalan di pohon pake cara post-order.
// Urutannya: Kiri -> Kanan -> Root.
void postOrderTraversal(Node* root) {
    // Kalo nodenya udah null (ujung pohon), ya udah stop.
    if (root == nullptr) {
        return;
    }

    // 1. "Nyelam" dulu ke anak kiri sampe abis.
    postOrderTraversal(root->left);

    // 2. Abis itu, "nyelam" ke anak kanan sampe abis.
    postOrderTraversal(root->right);

    // 3. Terakhir, baru deh kita proses (cetak) data node yang sekarang.
    cout << root->data << " ";
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

    cout << "Post-order traversal dari tree adalah: ";
    postOrderTraversal(root);
    cout << endl;
    return 0;
}