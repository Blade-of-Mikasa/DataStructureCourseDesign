#include<bits/stdc++.h>
#include "../HeaderFile/all_header.h"
#include "./static_operation/deal_str.cpp"
#include "./static_operation/file_oi.cpp"
#include "./static_operation/regularization.cpp"
#include "./dynamic_operation/computing_time.cpp"
#include "./dynamic_operation/search.cpp"
#include "./dynamic_operation/repeat_function.cpp"
using namespace std;
const int MAXN = 1e6 + 10;
// const Myword voidword = {"", 0};

string* str = new string[MAXN];//中转变量, 用来短暂储存文件中的内容
Myword warr[MAXN];

//数据结构
SequenceList<Myword> slist, slist_order;
LinkedList<Myword> lklist;
BinarySearchTree<Myword> bst;
AVLTree<Myword> avl;
HashTable ht1;//基于拉链法的哈希表
HashTable ht2(nullptr, true);//基于开放寻址的哈希表

// 函数声明
int prepare();
int bulid_structure();//返回 0 表示成功

void linearMenu();
void linkedMenu();
void binaryTreeSearchMenu();//二叉排序树子菜单
void balanceBinarySearchMenu();//平衡二叉树子菜单
void hashTableMenu();//哈希表子菜单
void showMainMenu();// 主菜单

bool writeSuccess = false;
double Time = 0, ASL = 0;
int size =  prepare(), cnt = 1000;
Myword target = {"practices", 0};
SearchRes find_information;

int main() {
    bulid_structure();//构建结构
    // 使用 lambda 表达式来传递 QuickSort 函数及其参数
    Time = measureTime([&]() { QuickSort(warr, 0, size - 1); });
    // Time = measureTime([&]() { BubbleSort(warr, 0, size - 1); });
    cout << "排序时间: " << Time / CLOCKS_PER_SEC << "s" << endl;
    for(int i = 0; i < size; i++)
    slist_order.add(warr[i]);

    int choice;
    do {
        showMainMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                // 进入线性表子菜单
                linearMenu();
                break;
            case 2:
                // 进入链表子菜单
                linkedMenu();
                break;
            case 3:
                // 进入二叉树子菜单
                binaryTreeSearchMenu();
                break;
            case 4:
                balanceBinarySearchMenu(); // 进入平衡二叉树子菜单
                break;
            case 5:
                hashTableMenu(); // 进入哈希表子菜单
                break;
            case 0:
                cout << "退出系统..." << endl;
                break;
            default:
                cout << "无效选择，请重新输入！" << endl;
        }
        cout << endl;
    } while (choice != 0);

// 顺序表线性查找
{
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
}


    // 有序顺序表二分查找
{


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


//链表查找
{


    // 查找全部元素
    Time = ASL = 0;
    for (int i = 0; i < size; ++i)
    {
        Time += measureTime([&]()
                            { find_information = lklist.search_in_linked_list(warr[i]); });
        ASL += find_information.search_len;
    }
    cout << "链表查找平均查找时间:" << Time / CLOCKS_PER_SEC / size << endl;
    cout << "链表查找平均查找长度:" << ASL / size << endl;

}

 //二叉搜索树
 {

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

//拉链法哈希表
{
    // 查找全部元素
    Time = ASL = 0;
    for (int i = 0; i < size; ++i)
    {
        Time += measureTime([&]()
                            { find_information = ht1.find(warr[i]); });
        ASL += find_information.search_len;
    }
    cout<<"拉链法哈希表平均查找时间:"<<Time / CLOCKS_PER_SEC / size<<endl;
    cout<<"拉链法哈希表平均查找长度:"<<ASL / size<<endl;
}

//线性探测法哈希表
{
    // 查找全部元素
    Time = ASL = 0;
    for (int i = 0; i < size; ++i)
    {
        Time += measureTime([&]()
                            { find_information = ht2.find(warr[i]); });
        ASL += find_information.search_len;
    }
    cout<<"线性探测法哈希表平均查找时间:"<<Time / CLOCKS_PER_SEC / size<<endl;
    cout<<"线性探测法哈希表平均查找长度:"<<ASL / size<<endl;

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
    return size;
}

int bulid_structure()
{
    for(int i = 0; i < size; i++)
    {
        slist.add(warr[i]);
        lklist.add(warr[i]);
        bst.insert(warr[i]);
        avl.insert(warr[i]);
        ht1.insert(warr[i]);
        ht2.insert(warr[i]);
    }
    return 0;
}


void showMainMenu() {
    cout << "========== 查找系统 ==========" << endl;
    cout << "1. 基于顺序表的查找" << endl;
    cout << "2. 基于链表的查找" << endl; // 可扩展更多功能
    cout << "3. 基于二叉排序树的查找" << endl; // 可扩展更多功能
    cout << "4. 基于平衡二叉树的查找" << endl; // 可扩展更多功能
    cout << "5. 基于哈希表的查找" << endl; // 可扩展更多功能
    cout << "0. 退出系统" << endl;
    cout << "==============================" << endl;
    cout << "请输入您的选择: ";
}

// 顺序表子菜单
void linearMenu() {
    int choice;
    do {
        cout << "\n===== 线性表查找菜单 =====" << endl;
        cout << "1. 顺序查找" << endl;
        cout << "2. 二分查找" << endl;
        cout << "0. 返回主菜单" << endl;
        cout << "=========================" << endl;
        cout << "请输入您的选择: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout<<"输入单词"<<endl;
                cin >> target.str;
                cout<<"输入单词"<<endl;
                cin >> target.str;
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
                break;
            case 1:
                cout<<"输入单词"<<endl;
                cin >> target.str;
                cout<<"输入单词"<<endl;
                cin >> target.str;
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
                // TODO: 实现具体的线性表二分查找逻辑
                break;
            case 0:
                cout << "返回主菜单..." << endl;
                break;
            default:
                cout << "无效选择，请重新输入！" << endl;
        }
    } while (choice != 0);
}

// 链表子菜单
void linkedMenu() {
    int choice;
    do {
        cout << "\n===== 顺序表查找菜单 =====" << endl;
        cout << "1. 顺序查找" << endl;
        cout << "0. 返回主菜单" << endl;
        cout << "=========================" << endl;
        cout << "请输入您的选择: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout<<"输入单词"<<endl;
                cin >> target.str;
                cout << "执行顺序表的顺序查找..." << endl;
                // 多次查找同一元素
                Time = 0;
                int buf = cnt;
                while (buf--)
                {
                    Time += measureTime([&]()
                                        { lklist.search_in_linked_list(target); });
                }
                cout << "链表查找时间:" << Time / CLOCKS_PER_SEC / cnt << endl;
                break;
            case 0:
                cout << "返回主菜单..." << endl;
                break;
            default:
                cout << "无效选择，请重新输入！" << endl;
        }
    } while (choice != 0);
}


void binaryTreeSearchMenu(){
    int choice;
    do {
        cout << "\n===== 二叉排序树查找菜单 =====" << endl;
        cout << "1. 二叉排序树查找" << endl;
        cout << "0. 返回主菜单" << endl;
        cout << "=========================" << endl;
        cout << "请输入您的选择: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout<<"输入单词"<<endl;
                cin >> target.str;
                cout << "执行二叉排序树查找..." << endl;
                // 多次查找同一元素
                Time = 0;
                int buf = cnt;
                while (buf--)
                {
                    Time += measureTime([&](){
                        bst.search_in_tree(target); });
                }
                cout << "二叉搜索树时间:" << Time / CLOCKS_PER_SEC / cnt << endl;
                break;
            case 0:
                cout << "返回主菜单..." << endl;
                break;
            default:
                cout << "无效选择，请重新输入！" << endl;
        }
    } while (choice!= 0);
}
void balanceBinarySearchMenu()
{
    int choice;
    do {
        cout << "\n===== 平衡二叉树查找菜单 =====" << endl;
        cout << "1. 平衡二叉树查找" << endl;
        cout << "0. 返回主菜单" << endl;
        cout << "=========================" << endl;
        cout << "请输入您的选择: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout<<"输入单词"<<endl;
                cin >> target.str;
                cout << "执行平衡二叉树查找..." << endl;
                // 多次查找同一元素
                Time = 0;
                int buf = cnt;
                while (buf--)
                {
                    Time += measureTime([&](){
                        avl.search_in_tree(target); });
                }
                cout << "平衡二叉树时间:" << Time / CLOCKS_PER_SEC / cnt << endl;
                break;
            case 0:
                cout << "返回主菜单..." << endl;
                break;
            default:
                cout << "无效选择，请重新输入！" << endl;
        }
    } while (choice!= 0);
}

void hashTableMenu(){
    int choice;
    do {
        cout << "\n===== 哈希表查找菜单 =====" << endl;
        cout << "1. 拉链法查找" << endl;
        cout << "2. 开放定址法查找" << endl;
        cout << "0. 返回主菜单" << endl;
        cout << "=========================" << endl;
        cout << "请输入您的选择: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout<<"输入单词"<<endl;
                cin >> target.str;
                cout << "执行拉链法查找..." << endl;
                Time = 0;
                int buf = cnt;
                while (buf--)
                {
                    Time += measureTime([&]()
                                        { ht1.find(target); });
                }
                cout << "拉链法哈希表时间:" << Time / CLOCKS_PER_SEC / cnt << endl;
                break;
            case 2:
                cout<<"输入单词"<<endl;
                cin >> target.str;
                cout << "执行开放定址法查找..." << endl;
                // 多次查找同一元素
                Time = 0;
                int buf = cnt;
                while (buf--)
                {
                    Time += measureTime([&]()
                                        { ht2.find(target); });
                }
                cout << "线性探测法哈希表时间:" << Time / CLOCKS_PER_SEC / cnt << endl;
                break;
            case 0:
                cout << "返回主菜单..." << endl;
                break;
            default:
                cout << "无效选择，请重新输入！" << endl;
        }
    } while (choice!= 0);
}