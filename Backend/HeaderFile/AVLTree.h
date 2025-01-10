#pragma once
#include <iostream>
// 二叉平衡树模板类实现（AVL树）
template <typename T>
class AVLTree {
private:
    struct Node {
        T value;
        Node* left;
        Node* right;
        int height;

        Node(const T& value) : value(value), left(nullptr), right(nullptr), height(1) {}
    };

    Node* root;

    int height(Node* node) {
        return node ? node->height : 0;
    }

    int balanceFactor(Node* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = std::max(height(y->left), height(y->right)) + 1;
        x->height = std::max(height(x->left), height(x->right)) + 1;

        return x;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = std::max(height(x->left), height(x->right)) + 1;
        y->height = std::max(height(y->left), height(y->right)) + 1;

        return y;
    }

    Node* insert(Node* node, const T& value) {
        if (!node) return new Node(value);

        if (value < node->value) {
            node->left = insert(node->left, value);
        } else if (value > node->value) {
            node->right = insert(node->right, value);
        } else {
            return node;  // 不允许插入重复值
        }

        node->height = std::max(height(node->left), height(node->right)) + 1;

        int balance = balanceFactor(node);

        // 左左情况
        if (balance > 1 && value < node->left->value) {
            return rotateRight(node);
        }

        // 右右情况
        if (balance < -1 && value > node->right->value) {
            return rotateLeft(node);
        }

        // 左右情况
        if (balance > 1 && value > node->left->value) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // 右左情况
        if (balance < -1 && value < node->right->value) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    void inOrderTraversal(Node* node) const {
        if (!node) return;
        inOrderTraversal(node->left);
        std::cout << node->value << " ";
        inOrderTraversal(node->right);
    }

    void destroy(Node* node) {
        if (node) {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }

public:
    AVLTree() : root(nullptr) {}

    ~AVLTree() {
        destroy(root);
    }

    void insert(const T& value) {
        root = insert(root, value);
    }

    void inOrderTraversal() const {
        inOrderTraversal(root);
        std::cout << std::endl;
    }
};