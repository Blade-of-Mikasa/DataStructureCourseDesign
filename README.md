# CDODS

Course Design of Data Structure, 数据结构课程设计

### 扩容倍数

每次扩容 1.5 倍而不是两倍



### 存储问题

为什么要放在内存中?

warr 是一个中转变量, 考虑到访问频率, 处理以后一直储存在内存中, 加快读取速度. 由于缓存区大小限制, 没有使用 cpu cache 缓存加速

### 规避可能的 bug

C++ 的 bool 类型不稳定, 曾经出现过编译优化 bug.

x86-64 gcc 12.1 到 13.2 的 O2 优化下, `if (a==b)` 会被优化成 `if(!a)`[]
https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2020/p1964r2.html

### 内省排序

### 哈希函数
