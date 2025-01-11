#pragma once
#include<bits/stdc++.h>
#include "search_res.h"
// 链表模板类实现
template <typename T>
class LinkedList {
private:
    struct Node {
        T value;
        Node* next;

        Node(const T& value, Node* next = nullptr) : value(value), next(next) {}
    };

    Node* head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void add(const T& value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        ++ size;
    }

    void remove_at(int index) {
        if (index < 0 || index >= size) return;

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } 
        else {
            Node* current = head;
            for (int i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
        --size;
    }

    void insert_at(int index, const T& value) {
        if (index < 0 || index > size) return;

        if (index == 0) {
            head = new Node(value, head);
        } else {
            Node* current = head;
            for (int i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            current->next = new Node(value, current->next);
        }
        ++size;
    }


    void set(int index, const T& value) {
        if (index < 0 || index >= size) throw "Index out of bounds";
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        current->value = value;
    }

    SearchRes search_in_linked_list(const T& value) const {
        int cnt = 0;
        Node* current = head;
        while (current != nullptr) {
            cnt++;
            if (current->value == value) 
                return {value, cnt, 0, 1};
            current = current->next;
        }
        return (SearchRes){value, cnt, 0, 0};
    }


    T get(int index) const {
        if (index < 0 || index >= size) throw "Index out of bounds";
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->value;
    }

    int getSize() const {
        return size;
    }
};