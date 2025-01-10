#include<bits/stdc++.h>
using namespace std;

// 插入排序
template<typename T>
void InsertSort(T arr[], int l, int r);

// 堆排序
// 调整堆
template <typename T>
void HeapAdjust(T arr[], int start, int length);
// 入口
template <typename T>
void HeapSort(T arr[], int l, int r);

// 内省排序
// 排序
template <typename T>
void IntroSort(T arr[], int l, int r, int depthLimit);
// 入口
template <typename T>
void IntroSort(T arr[], int l, int r);


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
void HeapAdjust(T arr[], int start, int length)
{
    T temp = arr[start];
    int i = 2 * start + 1;
    while(i < length)
    {
        if(i + 1 < length && arr[i] < arr[i + 1])
            i++;
        if(arr[i] > temp)
        {
            arr[start] = arr[i];
            start = i;
            i = 2 * start + 1;
        }
        else
            break;
    }
    arr[start] = temp;
}


template<typename T>
void HeapSort(T arr[], int l, int r)
{
    // 构建堆
    for(int i = (r - 1) / 2; i >= l; i--)
        HeapAdjust(arr, i, r);

    // 进行堆排序
    for(int i = r - 1; i > l; i--)
    {
        swap(arr[l], arr[i]);
        HeapAdjust(arr, l, i);
    }
}


template <typename T>
void IntroSort(T arr[], int l, int r, int depthLimit) {
    if (r - l <= 16) {
        InsertSort(arr, l, r);
        return;
    }
    if (depthLimit == 0) {
        HeapSort(arr, l, r);
        return;
    }

    int pivotIndex = l + (r - l) / 2;
    T pivot = arr[pivotIndex];
    swap(arr[pivotIndex], arr[r - 1]);
    int i = l, j = r - 1;

    while (i <= j) {
        while (i <= j && arr[i] < pivot) i++;
        while (i <= j && arr[j] > pivot) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    swap(arr[i], arr[r - 1]);

    IntroSort(arr, l, i - 1, depthLimit - 1);
    IntroSort(arr, i + 1, r, depthLimit - 1);
}

template <typename T>
void IntroSort(T arr[], int l, int r) {
    int depthLimit = 2 * log2(r - l + 1);
    IntroSort(arr, l, r, depthLimit);
}

int a[100030];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    IntroSort(a, 0, n - 1);

    for(int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
