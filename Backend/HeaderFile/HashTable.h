#pragma once
#include <iostream>
#include <string>
#include <functional> // For custom hash function
#include "search_res.h"

const int TABLE_SIZE = 1e5 + 1; // 哈希表大小

// 拉链法节点结构
struct Node {
    string key;
    int value;
    Node* next;

    Node(const string& k, int v) : key(k), value(v), next(nullptr) {}
};

class HashTable {
private:
    // 拉链法的桶
    Node* table[TABLE_SIZE];

    // 开放地址法的状态
    string keys[TABLE_SIZE]; // 存储键
    int values[TABLE_SIZE];       // 存储值
    bool used[TABLE_SIZE];        // 标记是否使用

    function<int(const string&)> hashfunc;
    bool useOpenAddressing; // 碰撞处理模式：true 为开放地址法，false 为拉链法

public:
    // 构造函数
    HashTable(function<int(const string&)> customHashFunc = nullptr, bool openAddressing = false)
        : useOpenAddressing(openAddressing) {

        if (customHashFunc) {
            hashfunc = customHashFunc;
        } else {
            // 默认哈希函数（取模法）
            hashfunc = [](const string& key) {
                int hash = 0;
                for (char c : key) {
                    hash = (hash * 31 + c) % TABLE_SIZE;
                }
                return hash;
            };
        }

        // 初始化拉链法表
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = nullptr;
        }

        // 初始化开放地址法表
        for (int i = 0; i < TABLE_SIZE; ++i) {
            keys[i] = "";
            values[i] = 0;
            used[i] = false;
        }
    }

    // 插入函数
    void insert(const Myword& buf) {
        const string &key = buf.str;
        int value = buf.freq;
        int hash = hashfunc(key);

        if (useOpenAddressing) {
            // 开放地址法
            for (int i = 0; i < TABLE_SIZE; ++i) {
                int index = (hash + i) % TABLE_SIZE;
                if (!used[index] || keys[index] == key) {
                    keys[index] = key;
                    values[index] = value;
                    used[index] = true;
                    return;
                }
            }
            cerr << "Error: Hash table is full.\n";
        } else {
            // 拉链法
            Node* newNode = new Node(key, value);
            newNode->next = table[hash];
            table[hash] = newNode;
        }
    }

    // 查找函数
    SearchRes find(const Myword& buf) {
        const string &key = buf.str;
        int hash = hashfunc(key);
        int cnt = 0, value;

        if (useOpenAddressing) {
            // 开放地址法
            for (int i = 0; i < TABLE_SIZE; ++i) {
                cnt++;
                int index = (hash + i) % TABLE_SIZE;
                if (!used[index]) 
                    return {{key, 0}, cnt, 0, 0}; // 未找到
                if (keys[index] == key) {
                    value = values[index];
                    return {{key, value}, cnt, 0, 1};
                }
            }
        } 
        else {
            // 拉链法
            Node* current = table[hash];
            while (current) {
                cnt++;
                if (current->key == key) {
                    value = current->value;
                    return {{key, value}, cnt, 0, 1};
                }
                current = current->next;
            }
        }
        return {{key, 0}, cnt, 0, 0};
    }

    // 删除函数
    void remove(const string& key) {
        int hash = hashfunc(key);

        if (useOpenAddressing) {
            // 开放地址法
            for (int i = 0; i < TABLE_SIZE; ++i) {
                int index = (hash + i) % TABLE_SIZE;
                if (!used[index]) return; // 未找到
                if (keys[index] == key) {
                    used[index] = false;
                    keys[index] = "";
                    values[index] = 0;
                    return;
                }
            }
        } else {
            // 拉链法
            Node* current = table[hash];
            Node* prev = nullptr;

            while (current) {
                if (current->key == key) {
                    if (prev) {
                        prev->next = current->next;
                    } else {
                        table[hash] = current->next;
                    }
                    delete current;
                    return;
                }
                prev = current;
                current = current->next;
            }
        }
    }

    // 析构函数
    ~HashTable() {
        if (!useOpenAddressing) {
            for (int i = 0; i < TABLE_SIZE; ++i) {
                Node* current = table[i];
                while (current) {
                    Node* temp = current;
                    current = current->next;
                    delete temp;
                }
            }
        }
    }
};
