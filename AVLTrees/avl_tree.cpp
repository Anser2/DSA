#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
    
    Node(int val) {
        key = val;
        left = right = nullptr;
        height = 1;
    }
};

int height(Node* n) {
    return (n == nullptr) ? 0 : n->height;
}

int getBalance(Node* n) {
    if (n == nullptr) return 0;
    return height(n->left) - height(n->right);
}

Node* rightRotate(Node* y) {
    cout << "Right rotation on " << y->key << endl;
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    cout << "Left rotation on " << x->key << endl;
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node* insert(Node* root, int key) {
    if (root == nullptr)
        return new Node(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root; // no duplicates

    // Update height
    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    // Case LL
    if (balance > 1 && key < root->left->key)
        return rightRotate(root);

    // Case RR
    if (balance < -1 && key > root->right->key)
        return leftRotate(root);

    // Case LR
    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Case RL
    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = nullptr;

    // You can change this sequence to trigger all 4 rotations:
    root = insert(root, 30);
    root = insert(root, 20); // LL
    root = insert(root, 10); // LL

    root = insert(root, 40); // RR
    root = insert(root, 50); // RR

    root = insert(root, 25); // LR
    root = insert(root, 5);  // RL

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    return 0;
}
