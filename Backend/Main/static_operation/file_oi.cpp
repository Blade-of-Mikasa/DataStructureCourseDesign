#include <iostream>
#include <fstream>
#include <string>
#include "../../HeaderFile/all_header.h"
using namespace std;

bool readFileToWordArray(const string &filePath, string *wordArray, int maxWords, int &wordCount);

//模板输出
template<typename T>
bool writeToFile(const string &filePath, const T *warr, int size);


// 函数：读取文件并将单词存储到数组中
bool readFileToWordArray(const string& filePath, string* wordArray, int maxWords, int& wordCount) {
    ifstream file(filePath); // 打开文件
    if (!file.is_open()) {
        cerr << "无法打开文件: " << filePath << endl;
        return false;
    }

    wordCount = 1; // 初始化单词计数器
    string word;
    char c;

    while (file.get(c)) { // 逐字符读取文件
        if (isalnum(c) || c == '-' || c == '\'') {
            word += c; // 将字符添加到当前单词
        } 
        else if (!word.empty()) {
            // 如果当前字符不是单词字符且已收集到一个单词
            if (wordCount < maxWords) {
                wordArray[wordCount++] = word; // 存储单词到数组中
            } 
            else {
                cout << "单词数量超过数组容量 (" << maxWords << ")" << endl;
                break;
            }
            word.clear(); // 清空当前单词
        }
    }

    // 处理文件末尾的最后一个单词
    if (!word.empty() && wordCount < maxWords) {
        wordArray[wordCount++] = word;
    }
    else if(wordCount >= maxWords){
        cerr << "单词数量超过数组容量 (" << maxWords << ")" << endl;
    }

    // cout << endl;
    // debug2(wordCount, maxWords);
    // cout << endl;
    file.close(); // 关闭文件
    return true;
}

template<typename T>
bool writeToFile(const string &filePath, const T *warr, int size){
    ofstream file(filePath); // 打开文件
    if (!file.is_open()) {
        cerr << "无法打开文件: " << filePath << endl;
        return false;
    }
    file << size << endl;
    for(int i = 0; i < size; i ++){
        file << warr[i] << endl;
    }
    file.close(); // 关闭文件
    return true;
}
