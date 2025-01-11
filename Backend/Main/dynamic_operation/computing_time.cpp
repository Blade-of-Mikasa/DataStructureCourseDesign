#include <bits/stdc++.h>
#include <chrono> // 包含 chrono 头文件用于时间测量
#include "../../HeaderFile/all_header.h"
using namespace std;

template <typename Func, typename... Args>
double measureTime(Func A, Args&&... args) {
    // 使用 std::chrono::high_resolution_clock 测量时间
    auto start = std::chrono::high_resolution_clock::now(); // 获取开始时间点

    A(forward<Args>(args)...); // 执行传入的函数

    auto end = std::chrono::high_resolution_clock::now(); // 获取结束时间点

    // 计算并返回执行时间，单位为毫秒
    return std::chrono::duration<double, std::milli>(end - start).count();
}
