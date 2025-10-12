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

// Fungsi buat ngitung ada berapa banyak node di dalem pohon.
int countNodes(Node* root) {
    // Kalo pohonnya kosong (root-nya null), ya berarti nodenya 0.
    if (root == nullptr) {
        return 0;
    }
    
    // Kalo ada isinya, kita itung node sekarang (itung 1),
    // terus panggil fungsi ini lagi buat ngitung semua node di anak kiri,
    // sama semua node di anak kanan. Totalnya tinggal dijumlahin semua.
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);

    cout << "Jumlah total node dalam tree adalah: " << countNodes(root) << endl;
    return 0;
}