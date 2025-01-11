#pragma once
#include <bits/stdc++.h>
#include "search_res.h"
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

    // 插入节点的辅助函数
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

    // 查找节点的辅助函数
    virtual Node* search(Node* node, T value) {
        if (node == nullptr || node->data == value) {
            return node;
        }
        if (value < node->data) {
            return search(node->left, value);
        }
        return search(node->right, value);
    }

    // 查找最小值节点的辅助函数
    virtual Node* findMin(Node* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }

    // 删除节点的辅助函数
    virtual Node* remove(Node* node, T value) {
        if (node == nullptr) return node;

        if (value < node->data) {
            node->left = remove(node->left, value);
        } else if (value > node->data) {
            node->right = remove(node->right, value);
        } else {
            // 找到需要删除的节点
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

    // 中序遍历的辅助函数（用于调试）
    virtual void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

public:
    BinarySearchTree() : root(nullptr) {}

    // 插入值
    virtual void insert(T value) {  // 改为 virtual
        root = insert(root, value);
    }

    // 查找值
    virtual bool search(T value) {
        return search(root, value) != nullptr;
    }

    // 删除值
    virtual void remove(T value) {
        root = remove(root, value);
    }

    // 按中序遍历打印树（用于测试）
    virtual void inorder() {
        inorder(root);
        cout << endl;
    }

    //前序遍历
    virtual void preorder(Node* node) {
        if (node == nullptr) return;
        // filePath << node->data << " ";
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    //查找结果, first 是地址, second 是查找长度
    virtual SearchRes search_in_tree(T value) {
        int sl = 0;
        Node* node = root;
        while (node != nullptr) {
            sl++;
            if (node->data == value) {
                return {node->data, sl, 0, 1}; // 返回目标字符串在数组中的索引
            } else if (value < node->data) {
                node = node->left;
            } else {
                node = node->right;
            }
        }
        return {value, sl, 0, 0}; // 如果目标不存在于数组中，返回-1
    }


    //输出到文件
    // virtual void output_to_file_by_preorder(const string& filename) {
    //     ifstream file(filePath); // 打开文件
    //     if (!file.is_open()) {
    //     cerr << "无法打开文件: " << filePath << endl;
    //     return false;
    //     }
    //     prerder(root, filePath);
    //     file.close(); // 关闭文件
    // }

};
