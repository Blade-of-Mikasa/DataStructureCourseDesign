#include<bits/stdc++.h>
#include "../../HeaderFile/all_header.h"
using namespace std;

template<typename T>
SearchRes search_in_linear_structure(SequenceList<T> &str, int size,  T target);

template <typename T>
SearchRes binary_search(SequenceList<T> &str, int size, T target);

//模板类, 返回目标字符串在数组中的索引
template<typename T>
SearchRes search_in_linear_structure(SequenceList<T> &str, int size,  T target) {
    int sl = 0;
    for (int i = 0; i < size; i++) {
        sl++;
        if (str[i] == target) {
            return {str[i], i, sl, 1, 1}; // 返回目标字符串在数组中的索引
        }
    }
    return {-1, sl, 1, 0}; // 如果目标字符串不存在于数组中，返回-1
}

//模板类二分查找
template<typename T>
SearchRes binary_search(SequenceList<T> &str, int size, T target) {
    int l = 0, r = size - 1;
    int sl = 0;
    while (l <= r) {
        sl++;
        int mid = l + ((r - l) / 2);
        // debug2(mid, str[mid]);
        if (str[mid] == target) {
            return {str[mid], mid, sl, 1, 1}; // 返回目标字符串在数组中的索引
        } 
        else if (str[mid] < target) {
            l = mid + 1;
        } 
        else {
            r = mid - 1;
        }
    }
    return {-1, sl, 1, 0}; // 如果目标字符串不存在于数组中，返回-1
}
