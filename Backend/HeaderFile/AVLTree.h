#pragma once
#include<algorithm>
#include "search_res.h"
using namespace std;

template<typename T>
class AVLTree : public BinarySearchTree<T> {
private:
    // 辅助函数：获取节点的高度
    int height(typename BinarySearchTree<T>::Node* node) {
        if (node == nullptr) return 0;
        return 1 + std::max(height(node->left), height(node->right));
    }

    // 辅助函数：获取节点的平衡因子
    int balanceFactor(typename BinarySearchTree<T>::Node* node) {
        if (node == nullptr) return 0;
        return height(node->left) - height(node->right);
    }

    // 左旋转操作
    typename BinarySearchTree<T>::Node* leftRotate(typename BinarySearchTree<T>::Node* z) {
        typename BinarySearchTree<T>::Node* y = z->right;
        typename BinarySearchTree<T>::Node* T2 = y->left;

        // 执行旋转
        y->left = z;
        z->right = T2;

        return y;
    }

    // 右旋转操作
    typename BinarySearchTree<T>::Node* rightRotate(typename BinarySearchTree<T>::Node* y) {
        typename BinarySearchTree<T>::Node* x = y->left;
        typename BinarySearchTree<T>::Node* T2 = x->right;

        // 执行旋转
        x->right = y;
        y->left = T2;

        return x;
    }

    // 平衡指定节点的树
    typename BinarySearchTree<T>::Node* balance(typename BinarySearchTree<T>::Node* node) {
        int balance = balanceFactor(node);

        // 左子树过重
        if (balance > 1) {
            // 左右失衡情况
            if (balanceFactor(node->left) < 0) {
                node->left = leftRotate(node->left);
            }
            return rightRotate(node);
        }

        // 右子树过重
        if (balance < -1) {
            // 右左失衡情况
            if (balanceFactor(node->right) > 0) {
                node->right = rightRotate(node->right);
            }
            return leftRotate(node);
        }

        return node; // 不需要平衡
    }

    // 重写插入函数，确保满足AVL树的性质
    typename BinarySearchTree<T>::Node* insert(typename BinarySearchTree<T>::Node* node, T value) override {
        node = BinarySearchTree<T>::insert(node, value); // 调用基类的插入函数

        // 平衡节点
        return balance(node);
    }

    // 重写删除函数，确保满足AVL树的性质
    typename BinarySearchTree<T>::Node* remove(typename BinarySearchTree<T>::Node* node, T value) override {
        node = BinarySearchTree<T>::remove(node, value); // 调用基类的删除函数

        // 平衡节点
        return balance(node);
    }

public:
    AVLTree() : BinarySearchTree<T>() {}

    // 重写插入、搜索和删除方法，确保满足AVL树的性质
    void insert(T value) override {
        this->root = insert(this->root, value);
    }

    void remove(T value) override {
        this->root = remove(this->root, value);
    }
    
    // 中序遍历打印树（用于测试）
    void inorder() {
        BinarySearchTree<T>::inorder();
    }

    //前序遍历
    void preorder() {
        BinarySearchTree<T>::preorder();
    }
};
