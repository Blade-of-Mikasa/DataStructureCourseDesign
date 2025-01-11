#include<bits/stdc++.h>
#include "../../HeaderFile/all_header.h"
using namespace std;

template <typename Func, typename... Args>
auto repeat_function(Func F, int n, Args&&... args) -> decltype(F(args...)) {
    decltype(F(args...)) result; // 声明返回值类型
    for (int i = 0; i < n; ++i) {
        result = F(forward<Args>(args)...); // 执行 F，保存结果
    }
    return result; // 返回最后一次执行的结果
}