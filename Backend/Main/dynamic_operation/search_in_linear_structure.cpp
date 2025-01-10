#include<bits/stdc++.h>
#include "../../../HeaderFile/all_header.h"
using namespace std;

//模板类顺序查找
template <class T>
int search_in_seq_by_traverse(T arr[], T key, int size)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == key)
            return i;
    }
    return -1;
}

//模板类二分查找
template <class T>
int search_in_seq_by_binary(T arr[], T key, int size)
{
    int left = 0, right = size - 1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] > key)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

template <class T>
int search_in_linkedlist_by_traverse(LinkedList<T> list, T key)
{
    int index = 0;
    Node<T>* current = list.head;
    while(current != nullptr)
    {
        if(current->value == key)
            return index;
        current = current->next;
        index++;
    }
    return -1;
}
