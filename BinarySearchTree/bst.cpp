#include <iostream>
using namespace std;

// Implementing Binary Search Tree
struct tree {
    tree* left = nullptr;
    tree* right = nullptr;
    int data;
};

class binary_search_tree {
    public:
        tree* root = nullptr;

        // Constructor
        binary_search_tree() {
            root = nullptr;
        }

        // Function to add a node to the tree
        void add_leaf(tree*& node, int value) {
            if (node == nullptr) {
                node = new tree();
                node->data = value;
                node->left = nullptr;
                node->right = nullptr;
            } else if (value < node->data) {
                add_leaf(node->left, value);
            } else if (value > node->data) {
                add_leaf(node->right, value);
            } else {
                cout << "Value already exists in the tree" << endl;
            }
        }

        // Wrapper function to add a node starting from the root
        void add_leaf(int value) {
            add_leaf(root, value);
        }

        // In-order traversal to display the tree
        void in_order_traversal(tree* node) {
            if (node != nullptr) {
                in_order_traversal(node->left);
                cout << node->data << " ";
                in_order_traversal(node->right);
            }
        }
        // Pre-order traversal to display the tree
        void pre_order_traversal(tree* node) {
            if (node != nullptr) {
                cout << node->data << " ";
                pre_order_traversal(node->left);
                pre_order_traversal(node->right);
            }
        }   
        // Post-order traversal to display the tree 
        void post_order_traversal(tree* node) {
            if (node != nullptr) {
                post_order_traversal(node->left);
                post_order_traversal(node->right);
                cout << node->data << " ";
            }
        }

        void display(char order) {
            if (order == 'i') {
                in_order_traversal(root);
            } else if (order == 'p') {
                pre_order_traversal(root);
            } else if (order == 'o') {
                post_order_traversal(root);
            } else {
                cout << "Invalid order specified" << endl;
            }
        }

        // Find the minimum value node in a subtree
        tree* find_min(tree* node) {
            while (node->left != nullptr) {
                node = node->left;
            }
            return node;
        }

        // Function to remove a node from the tree
        tree* remove_node(tree* node, int value) {
            if (node == nullptr) {
                cout << "Value not found in the tree" << endl;
                return node;
            }

            if (value < node->data) {
                node->left = remove_node(node->left, value);
            } else if (value > node->data) {
                node->right = remove_node(node->right, value);
            } else {
                // Node with only one child or no child
                if (node->left == nullptr) {
                    tree* temp = node->right;
                    delete node;
                    return temp;
                } else if (node->right == nullptr) {
                    tree* temp = node->left;
                    delete node;
                    return temp;
                }

                // Node with two children: Get the in-order successor (smallest in the right subtree)
                tree* temp = find_min(node->right);

                // Copy the in-order successor's data to this node
                node->data = temp->data;

                // Delete the in-order successor
                node->right = remove_node(node->right, temp->data);
            }
            return node;
        }

        // Wrapper function to remove a node starting from the root
        void remove(int value) {
            root = remove_node(root, value);
        }

        void delete_tree(tree*& node) {
            if (node != nullptr) {
                delete_tree(node->left);
                delete_tree(node->right);
                delete node;
                node = nullptr;
            }
        }
};

int main() {
    binary_search_tree bst;
    cout << "BINARY SEARCH TREE Menu" << endl;
    cout << "1. Add Data" << endl;
    cout << "2. Pre-order Traversal" << endl;
    cout << "3. In-order Traversal" << endl;
    cout << "4. Post-order Traversal" << endl;
    cout << "5. Remove Data" << endl;
    cout << "6. Delete Entire Tree" << endl;
    cout << "7. Exit" << endl;

    char choice;
    do {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                int value;
                cout << "Enter value to add: ";
                cin >> value;
                bst.add_leaf(value);
                break;
            }
            case '2':
                cout << "Pre-order Traversal: ";
                bst.display('p');
                cout << endl;
                break;
            case '3':
                cout << "In-order Traversal: ";
                bst.display('i');
                cout << endl;
                break;
            case '4':
                cout << "Post-order Traversal: ";
                bst.display('o');
                cout << endl;
                break;
            case '5': {
                int value;
                cout << "Enter value to remove: ";
                cin >> value;
                bst.remove(value);
                break;
            }
            case '6':
                bst.delete_tree(bst.root);
                cout << "Tree deleted" << endl;
                break;
            case '7':
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != '7');

    return 0;
}