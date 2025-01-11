#include<bits/stdc++.h>
using namespace std;
template<typename T>
class BinarySearchTree {
protected:  // 将 Node 从 private 改为 protected
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(T value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // Helper function for inserting a node
    virtual Node* insert(Node* node, T value) {  // 改为 virtual
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }
        return node;
    }

    // Helper function for finding a node
    virtual Node* search(Node* node, T value) {
        if (node == nullptr || node->data == value) {
            return node;
        }
        if (value < node->data) {
            return search(node->left, value);
        }
        return search(node->right, value);
    }

    // Helper function for finding the minimum value node
    virtual Node* findMin(Node* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }

    // Helper function for deleting a node
    virtual Node* remove(Node* node, T value) {
        if (node == nullptr) return node;

        if (value < node->data) {
            node->left = remove(node->left, value);
        } else if (value > node->data) {
            node->right = remove(node->right, value);
        } else {
            // Node to be deleted found
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
        return node;
    }

    // Helper function for inorder traversal (for debugging purposes)
    virtual void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

public:
    BinarySearchTree() : root(nullptr) {}

    // Insert a value
    virtual void insert(T value) {  // 改为 virtual
        root = insert(root, value);
    }

    // Search for a value
    virtual bool search(T value) {
        return search(root, value) != nullptr;
    }

    // Delete a value
    virtual void remove(T value) {
        root = remove(root, value);
    }

    // Print tree in-order (for testing purposes)
    virtual void inorder() {
        inorder(root);
        cout << endl;
    }
};



template<typename T>
class AVLTree : public BinarySearchTree<T> {
private:
    // Helper function to get the height of the node
    int height(typename BinarySearchTree<T>::Node* node) {
        if (node == nullptr) return 0;
        return 1 + std::max(height(node->left), height(node->right));
    }

    // Helper function to get the balance factor of a node
    int balanceFactor(typename BinarySearchTree<T>::Node* node) {
        if (node == nullptr) return 0;
        return height(node->left) - height(node->right);
    }

    // Left rotation
    typename BinarySearchTree<T>::Node* leftRotate(typename BinarySearchTree<T>::Node* z) {
        typename BinarySearchTree<T>::Node* y = z->right;
        typename BinarySearchTree<T>::Node* T2 = y->left;

        // Perform rotation
        y->left = z;
        z->right = T2;

        return y;
    }

    // Right rotation
    typename BinarySearchTree<T>::Node* rightRotate(typename BinarySearchTree<T>::Node* y) {
        typename BinarySearchTree<T>::Node* x = y->left;
        typename BinarySearchTree<T>::Node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        return x;
    }

    // Balance the tree at the given node
    typename BinarySearchTree<T>::Node* balance(typename BinarySearchTree<T>::Node* node) {
        int balance = balanceFactor(node);

        // Left heavy
        if (balance > 1) {
            // Left-right case
            if (balanceFactor(node->left) < 0) {
                node->left = leftRotate(node->left);
            }
            return rightRotate(node);
        }

        // Right heavy
        if (balance < -1) {
            // Right-left case
            if (balanceFactor(node->right) > 0) {
                node->right = rightRotate(node->right);
            }
            return leftRotate(node);
        }

        return node; // No balancing needed
    }

    // Override insert to maintain AVL property
    typename BinarySearchTree<T>::Node* insert(typename BinarySearchTree<T>::Node* node, T value) override {
        node = BinarySearchTree<T>::insert(node, value); // Call base insert

        // Balance the node
        return balance(node);
    }

    // Override remove to maintain AVL property
    typename BinarySearchTree<T>::Node* remove(typename BinarySearchTree<T>::Node* node, T value) override {
        node = BinarySearchTree<T>::remove(node, value); // Call base remove

        // Balance the node
        return balance(node);
    }

public:
    AVLTree() : BinarySearchTree<T>() {}

    // Override insert, search, and remove for AVL
    void insert(T value) override {
        this->root = insert(this->root, value);
    }

    void remove(T value) override {
        this->root = remove(this->root, value);
    }
    
    // Print tree in-order (for testing purposes)
    void inorder() {
        BinarySearchTree<T>::inorder();
    }
};


int main() {
    cout << "Testing Binary Search Tree (BST):" << endl;
    BinarySearchTree<int> bst;
    bst.insert(10);
    bst.insert(20);
    bst.insert(5);
    bst.insert(6);
    bst.insert(15);
    bst.inorder(); // Expected: 5 6 10 15 20

    bst.remove(10);
    bst.inorder(); // Expected: 5 6 15 20

    cout << "Searching for 15 in BST: " << (bst.search(15) ? "Found" : "Not Found") << endl;

    cout << "\nTesting AVL Tree:" << endl;
    AVLTree<int> avl;
    avl.insert(10);
    avl.insert(20);
    avl.insert(5);
    avl.insert(6);
    avl.insert(15);
    avl.inorder(); // Expected: 5 6 10 15 20 (balanced)

    avl.remove(10);
    avl.inorder(); // Expected: 5 6 15 20 (balanced)

    cout << "Searching for 15 in AVL: " << (avl.search(15) ? "Found" : "Not Found") << endl;

    return 0;
}