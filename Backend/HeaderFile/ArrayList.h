
#include <bits/stdc++.h>
// 顺序表模板类实现
template <typename T>
class ArrayList {
private:
    T* data;  // 存储顺序表数据的数组指针
    int capacity;  // 当前分配的容量
    int size;  // 当前存储的元素数量

    void resize(int newCapacity) {
        T* newData = new T[newCapacity];
        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    ArrayList(int initialCapacity = 10) : capacity(initialCapacity), size(0) {
        data = new T[capacity];
    }

    ~ArrayList() {
        delete[] data;
    }

    void add(const T& value) {
        if (size == capacity) {
            resize(capacity * 2);
        }
        data[size++] = value;
    }

    void removeAt(int index) {
        if (index < 0 || index >= size) return;
        for (int i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size;
    }

    T get(int index) const {
        if (index < 0 || index >= size) throw "Index out of bounds";
        return data[index];
    }

    int getSize() const {
        return size;
    }

    bool empty() const {
        return size == 0;
    }

    //运算重载[]
    T& operator[](int index) {
        if (index < 0 || index >= size) throw "Index out of bounds";
        return data[index];
    }
};