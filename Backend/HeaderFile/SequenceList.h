
#pragma once
// 顺序表模板类实现
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T, bool EnableDynamicResize = true>
class SequenceList {
private:
    T* data;               // 数据存储指针
    size_t capacity;       // 当前容量
    size_t size;           // 当前元素个数

    // 动态扩容函数
    void resize(size_t newCapacity) {
        if constexpr (EnableDynamicResize) { // 仅在启用动态扩容时执行
            T* newData = new T[newCapacity];
            for (size_t i = 0; i < size; ++i) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity = newCapacity;
        } else {
            throw overflow_error("Dynamic resizing is disabled. Cannot add more elements.");
        }
    }

    // 获取元素
    T& get(size_t index) {
        if (index >= size) {
            throw out_of_range("Index out of range.");
        }
        return data[index];
    }

public:
    // 构造函数
    SequenceList(size_t initialCapacity = 10) 
        : capacity(initialCapacity), size(0) {
        data = new T[capacity];
    }

    // 析构函数
    ~SequenceList() {
        delete[] data;
    }

    // 添加元素
    void add(const T& value) {
        if (size >= capacity) {
            if constexpr (EnableDynamicResize) {
                resize((int)(capacity * 1.5)); // 动态扩容为当前容量的1.5倍
            } else {
                throw overflow_error("Cannot add element. SequenceList is full.");
            }
        }
        data[size++] = value;
    }

    // 删除最后一个元素
    void removeLast() {
        if (size == 0) {
            throw underflow_error("Cannot remove element. SequenceList is empty.");
        }
        --size;
    }

    // 获取当前大小
    size_t getSize() const {
        return size;
    }

    // 获取当前容量
    size_t getCapacity() const {
        return capacity;
    }

    // 重载[]运算符
    T& operator[](size_t index) {
        return get(index);
    }

    // // 打印顺序表内容
    // void print() const {
    //     cout << "[ ";
    //     for (size_t i = 0; i < size; ++i) {
    //         cout << data[i] << " ";
    //     }
    //     cout << "]" << endl;
    // }
};
