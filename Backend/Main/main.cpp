#include<bits/stdc++.h>
#include "../HeaderFile/all_header.h"
#include "./static_operation/deal_str.cpp"
#include "./static_operation/file_oi.cpp"
#include "./static_operation/regularization.cpp"
// #include "./static_operation/change_to_node.cpp"

// #include "./dynamic_operation/search_in_linear_structure.cpp"
#include "./dynamic_operation/computing_time.cpp"
#include "./dynamic_operation/search.cpp"
#include "./dynamic_operation/repeat_function.cpp"

// #include "test.cpp"
using namespace std;
const int MAXN = 1e6 + 10;


//str 是一个中转变量, 用来短暂储存文件中的内容
string* str = new string[MAXN];

//warr 也是一个中转变量, 考虑到访问频率, 处理以后一直储存在内存中, 加快读取速度
//由于缓存区大小限制, 没有使用 cpu cache 缓存加速
Myword warr[MAXN];
const Myword voidword = {"", 0};

//数据结构
SequenceList<Myword> slist, slist_order;
LinkedList<Myword> lklist;
BinarySearchTree<Myword> bst;
AVLTree<Myword> avl;
// HashTable<Myword> ht;


int prepare();
int bulid_structure(int size);//返回 0 表示成功
bool out_copy_file(int size);

// void output_search_information(SearchRes find_information);

int main() {
    // test();
    bool writeSuccess = false;
    double Time = 0;
    double ASL = 0;
    // int search_len, average_search_len = 0;
    int size =  prepare();//准备
    bulid_structure(size);//构建结构
    bool all_out_ok = out_copy_file(size);

    // const string OutPath = "D:\\CDODS\\OutFile.txt";
    // writeSuccess = writeToFile(OutPath, warr, size);
    // if (writeSuccess) {
    //     cout << "成功将 Myword 输出到文件: " << OutPath << endl;
    // }

    // //统计排序时间
    // 使用 lambda 表达式来传递 QuickSort 函数及其参数
    Time = measureTime([&]() { QuickSort(warr, 0, size - 1); });
    // Time = measureTime([&]() { BubbleSort(warr, 0, size - 1); });
    cout << "排序时间: " << Time / CLOCKS_PER_SEC << "s" << endl;

    for(int i = 0; i < size; i++)
        slist_order.add(warr[i]);

    // const string OutPath2 = "D:\\CDODS\\OutFile2.txt";
    // writeSuccess = writeToFile(OutPath2, warr, size);
    // if (writeSuccess) {
    //     cout << "成功将 Myword 输出到文件: " << OutPath2 << endl;
    // }


    // Time = 0;
    // while(cnt --)
    // {
    //     Time += measureTime([&]() {
    //         SearchRes find_information = search_in_linear_structure(slist, slist.getSize(), warr[rand() % size]);
    //     });
    // }


    //查找
    Myword target = {"practices", 0};
    SearchRes find_information;
    int cnt = 1000;
    // int Time = 0;


// 顺序表线性查找
{
    cout<<"顺序表线性查找: "<<endl;

    // 多次查找同一元素
    Time = 0;
    int buf = cnt;
    while (buf--)
    {
        Time += measureTime([&](){ 
            search_in_linear_structure(slist, slist.getSize(), target); });
    }
    cout << "线性查找时间:" << Time / CLOCKS_PER_SEC / cnt << endl;

    // 查找全部元素
    Time = 0;
    for (int i = 0; i < size; ++i)
    {
        Time += measureTime([&](){ 
            search_in_linear_structure(slist, slist.getSize(), warr[i]); });
    }
    cout << "线性查找平均查找时间:" << Time / CLOCKS_PER_SEC / size << endl;

    ASL = 0;
    for (int i = 0; i < size; ++i)
    {
        find_information = search_in_linear_structure(slist, slist.getSize(), warr[i]);
        ASL += find_information.search_len;
    }
    cout << "线性查找平均查找长度:" << ASL / size << endl;

    // // 线性查找
    // find_information = search_in_linear_structure(slist, slist.getSize(), target);
    // // output_search_information(find_information);
    // cout << "线性查找:" << endl;
    // cout<<find_information<<endl;
}


    // 有序顺序表二分查找
{
    // find_information = binary_search(slist_order, slist_order.getSize(), target);
    // // output_search_information(find_information);
    // cout << "二分查找:" << endl;
    // cout<<find_information<<endl;
    cout<<"有序顺序表二分查找: "<<endl;

    // 多次查找同一元素
    Time = 0;
    int buf = cnt;
    while (buf--)
    {
        Time += measureTime([&](){
            binary_search(slist_order, slist_order.getSize(), target); });
    }
    cout << "二分查找时间:" << Time / CLOCKS_PER_SEC / cnt << endl;

    // 查找全部元素
    Time = 0;
    for (int i = 0; i < size; ++i)
    {
        Time += measureTime([&](){
            binary_search(slist_order, slist_order.getSize(), warr[i]); });
    }
    cout << "二分查找平均查找时间:" << Time / CLOCKS_PER_SEC / size << endl;
    ASL = 0;
    for (int i = 0; i < size; ++i)
    {
        find_information = binary_search(slist_order, slist_order.getSize(), warr[i]);
        ASL += find_information.search_len;
    }
    cout << "二分查找平均查找长度:" << ASL / size << endl;

}


 //二叉搜索树
 {
    // find_information = bst.search_in_tree(target);
    // cout<<"二叉搜索树:"<<endl;
    // cout<<find_information<<endl;
    cout<<"二叉搜索树:"<<endl;

    // 多次查找同一元素
    Time = 0;
    int buf = cnt;
    while (buf--)
    {
        Time += measureTime([&](){
            bst.search_in_tree(target); });
    }
    cout << "二叉搜索树时间:" << Time / CLOCKS_PER_SEC / cnt << endl;
    // 查找全部元素
    Time = 0;
    for (int i = 0; i < size; ++i)
    {
        Time += measureTime([&](){
            bst.search_in_tree(warr[i]); });
    }
    cout << "二叉搜索树平均查找时间:" << Time / CLOCKS_PER_SEC / size << endl;
    ASL = 0;
    for (int i = 0; i < size; ++i)
    {
        find_information = bst.search_in_tree(warr[i]);
        ASL += find_information.search_len;
    }
    cout << "二叉搜索树平均查找长度:" << ASL / size << endl;

 }

//平衡二叉树
{
    // find_information = avl.search_in_tree(target);
    // cout<<"平衡二叉树:"<<endl;
    // cout<<find_information<<endl;
    cout<<"平衡二叉树:"<<endl;
    
    // 多次查找同一元素
    Time = 0;
    int buf = cnt;
    while (buf--)
    {
        Time += measureTime([&](){
            avl.search_in_tree(target); });
    }
    cout << "平衡二叉树时间:" << Time / CLOCKS_PER_SEC / cnt << endl;
    // 查找全部元素
    Time = 0;
    for (int i = 0; i < size; ++i)
    {
        Time += measureTime([&](){
            avl.search_in_tree(warr[i]); });
    }
    cout << "平衡二叉树平均查找时间:" << Time / CLOCKS_PER_SEC / size << endl;
    ASL = 0;
    for (int i = 0; i < size; ++i)
    {
        find_information = avl.search_in_tree(warr[i]);
        ASL += find_information.search_len;
    }
    cout << "平衡二叉树平均查找长度:" << ASL / size << endl;

}

    return 0;
}

int prepare()
{
    const string filePath = "D:\\CDODS\\InFile.txt";
    int maxWords = MAXN, wordCount = 0;
    bool readSuccess = readFileToWordArray(filePath, str, maxWords, wordCount);
    if (readSuccess) 
    {
        cout << "成功读取文件: " << filePath << endl;
        cout<<"单词数量:"<<wordCount<<endl;
    }

    regularize(str, wordCount);
    int size = unique_by_traverse(str, warr, wordCount);
    cout<<"不同单词数量:"<<size<<endl;
    //释放内存
    delete[] str;
    return size;
}

int bulid_structure(int size)
{
    for(int i = 0; i < size; i++)
    {
        slist.add(warr[i]);
        lklist.add(warr[i]);
        bst.insert(warr[i]);
        avl.insert(warr[i]);
        // ht.insert(warr[i]);
    }
    return 0;
}

bool out_copy_file(int size)
{
    const string allOutPath[] = {
        "../../OutFile.txt",
        "../../OutFile1.txt",
        "../../OutFile2.txt",
        "../../OutFile3.txt",
        "../../OutFile4.txt",
        "../../OutFile5.txt",
        "../../OutFile6.txt",
    };
    for(int i = 0; i < 7; i++){    
        bool writeSuccess = writeToFile(allOutPath[i], warr, size);
        if (writeSuccess) {
            cout << "成功将 Myword 输出到文件: " << allOutPath[i] << endl;
        }
    }
    return 1;
}