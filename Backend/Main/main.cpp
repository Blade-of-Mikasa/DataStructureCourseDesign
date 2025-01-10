#include<bits/stdc++.h>
#include "../HeaderFile/all_header.h"
#include "deal_str_to_word.cpp"
#include "file_oi.cpp"
#include "regularization.cpp"
using namespace std;
const int MAXN = 1e6 + 10;

string str[MAXN];
Myword warr[MAXN];

int main() {
    const string filePath = "D:\\CDODS\\InFile.txt";
    int maxWords = MAXN, wordCount = 0;
    bool readSuccess = readFileToWordArray(filePath, str, maxWords, wordCount);
    if (readSuccess) 
    {
        std::cout << "文件中的单词数量: " << wordCount << std::endl;
        std::cout << "文件中的数字: " << std::endl;
    }

    regularize(str);

    int size = unique_by_traverse(str, warr);

    // for(int i = 0; i < 10; i ++)
    //     cout << warr[i].str << " " << warr[i].freq << endl;

    cout<<"排序后:"<<endl;
    QuickSort(warr, 0, size - 1);

    // for(int i = 0; i < 10; i ++)
    //     cout << warr[i].str << " " << warr[i].freq << endl;


    // Windows 路径 P
    const std::string path = "D:\\CDODS\\OutFile.txt";
    std::ofstream file(path);

    // 检查文件是否成功打开
    if (!file.is_open()) {
        std::cerr << "无法打开文件: " << path << std::endl;
        return 1;
    }

    // 使用 << 将 Myword 写入文件
    for(int i = 0; i < size; i ++)
        file << warr[i] << endl;
        // file << warr[i].str << " " << warr[i].freq << std::endl;
        // file << "Hello, World!" << std::endl;

    // 关闭文件流
    file.close();

    std::cout << "成功将 Myword 输出到文件: " << path << std::endl;

    return 0;
}
