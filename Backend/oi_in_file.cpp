#include <iostream>
#include <fstream>
#include <string>
#include "HeaderFile\\word.h"
#include "HeaderFile\\ArrayList.h"
using namespace std;

bool readFileToStringArray(const string &filePath, string *stringArray, int maxLines, int &linesRead);

bool readFileToStringArray(const string& filePath, string* stringArray, int maxLines, int& linesRead) {
// filePath: 路径(Windows); stringArray: 存储内容的数组; maxLines: 数组最大容量; linesRead: 实际读取行数
    ifstream file(filePath); // 打开文件
    if (!file.is_open()) {        // 检查文件是否成功打开
        cerr << "Failed to open the file: " << filePath << endl;
        return false;
    }

    string line;
    linesRead = 0;

    while (getline(file, line)) { // 逐行读取文件内容
        if (linesRead >= maxLines) {   // 检查数组容量是否已满
            cerr << "Array capacity exceeded. Max lines: " << maxLines << endl;
            break;
        }
        stringArray[linesRead++] = line; // 将当前行存入数组
    }

    file.close(); // 关闭文件
    return true;
}

int main() {
    string filePath = "D:\\CDODS\\InFile.txt";
    string stringArray[1000];
    int buf = 1000;
    readFileToStringArray(filePath, stringArray, 1000, buf);
    for(int i = 0; i < 1000; i ++)
        cout << stringArray[i] << endl;
    return 0;
}
