#pragma once
#include<bits/stdc++.h>
using namespace std;

//冒泡排序
template <typename T>
void BubbleSort(T arr[], int l, int r);

//插入排序
template<typename T>
void InsertSort(T arr[], int l, int r);

// 快速排序
template <typename T>
void QuickSort(T arr[], int l, int r);

//堆排序
// 调整堆
template <typename T>
void HeapAdjust(T arr[], int start, int length);
// 入口
template <typename T>
void HeapSort(T arr[], int l, int r);

// // 内省排序
// // 排序
// template <typename T>
// void IntroSort(T arr[], int l, int r, int depthLimit);
// // 入口
// template <typename T>
// void IntroSort(T arr[], int l, int r);

template<typename T>
void BubbleSort(T arr[], int l,  int r)
{
    for(int i = l; i < r; i++)
    {
        for(int j = l; j < r - i + l; j++)
        {
            if(arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}


template<typename T>
void InsertSort(T arr[], int l, int r)
{
    for(int i = l + 1; i <= r; i++)
    {
        T temp = arr[i];
        int j = i - 1;
        while(j >= l && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

template<typename T>
void QuickSort(T arr[], int l, int r)
{
    if(l >= r)
        return;
    int i = l, j = r;
    T pivot = arr[l];
    while(i < j)
    {
        while(i < j && arr[j] >= pivot)
            j--;
        arr[i] = arr[j];
        while(i < j && arr[i] <= pivot)
            i++;
        arr[j] = arr[i];
    }
    arr[i] = pivot;
    QuickSort(arr, l, i - 1);
    QuickSort(arr, i + 1, r);
}

template<typename T>
void HeapAdjust(T arr[], int start, int length)
{
    T temp = arr[start];
    for(int i = 2 * start + 1; i < length; i = 2 * i + 1)
    {
        if(i + 1 < length && arr[i] < arr[i + 1])
            i++;
        if(arr[i] > temp)
        {
            arr[start] = arr[i];
            start = i;
        }
        else
            break;
    }
    arr[start] = temp;
}

template<typename T>
void HeapSort(T arr[], int l, int r)
{
    // 构建大根堆
    for(int i = (r - l) / 2; i >= 0; i--)
    {
        HeapAdjust(arr, i, r - l + 1);
    }
    // 排序
    for(int i = r - l; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        HeapAdjust(arr, 0, i);
    }
}



// template <typename T>
// void IntroSort(T arr[], int l, int r, int depthLimit) {
//     if (r - l <= 16) {
//         // 当子数组长度小于等于 16 时，使用插入排序
//         InsertSort(arr, l, r);
//         return;
//     }

//     if (depthLimit == 0) {
//         // 当递归深度超过限制时，使用堆排序
//         HeapSort(arr, l, r);
//         return;
//     }

//     // 使用快速排序的分区方法
//     int pivotIndex = l + (r - l) / 2;
//     T pivot = arr[pivotIndex];
//     swap(arr[pivotIndex], arr[r - 1]); // 将 pivot 放到最后一个位置
//     int i = l, j = r - 1;

//     for (int k = l; k < r - 1; ++k) {
//         if (arr[k] < pivot) {
//             swap(arr[i++], arr[k]);
//         }
//     }
//     swap(arr[i], arr[r - 1]); // 将 pivot 放到正确的位置

//     // 递归处理左右部分
//     IntroSort(arr, l, i, depthLimit - 1);
//     IntroSort(arr, i + 1, r, depthLimit - 1);
// }

// template <typename T>
// void IntroSort(T arr[], int l, int r) {
//     int depthLimit = 2 * log(r - l); // 最大递归深度限制
//     IntroSort(arr, l, r, depthLimit);
// }
