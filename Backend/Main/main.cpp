#include<bits/stdc++.h>
#include "../HeaderFile/all_header.h"
#include "./static_operation/deal_str.cpp"
#include "./static_operation/file_oi.cpp"
#include "./static_operation/regularization.cpp"
using namespace std;
const int MAXN = 1e6 + 10;


//动态申请内存
string* str = new string[MAXN];
Myword warr[MAXN];

int prepare();

int main() {
    //准备
    int size =  prepare();

    //统计排序时间
    clock_t start, end;
    start = clock();
    QuickSort(warr, 0, size - 1);
    end = clock();
    cout<<"排序时间:"<<(double)(end - start) / CLOCKS_PER_SEC<<"s"<<endl;

    //输出到文件
    const string OutPath = "D:\\CDODS\\OutFile.txt";
    bool writeSuccess = writeToFile(OutPath, warr, size);
    if (writeSuccess) {
        cout << "成功将 Myword 输出到文件: " << OutPath << endl;
    }

    cout << endl;
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