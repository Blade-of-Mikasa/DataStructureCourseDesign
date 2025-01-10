#include <iostream>
#include <fstream>
#include <string>
#include "../HeaderFile/all_header.h"
using namespace std;

bool readFileToWordArray(const std::string &filePath, std::string *wordArray, int maxWords, int &wordCount);

// 函数：读取文件并将单词存储到数组中
bool readFileToWordArray(const std::string& filePath, std::string* wordArray, int maxWords, int& wordCount) {
    std::ifstream file(filePath); // 打开文件
    if (!file.is_open()) {
        std::cerr << "无法打开文件: " << filePath << std::endl;
        return false;
    }

    wordCount = 0; // 初始化单词计数器
    std::string word;
    char c;

    while (file.get(c)) { // 逐字符读取文件
        if (std::isalnum(c) || c == '-' || c == '\'') {
            word += c; // 将字符添加到当前单词
        } 
        else if (!word.empty()) {
            // 如果当前字符不是单词字符且已收集到一个单词
            if (wordCount < maxWords) {
                wordArray[wordCount++] = word; // 存储单词到数组中
            } 
            else {
                std::cerr << "单词数量超过数组容量 (" << maxWords << ")" << std::endl;
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
        std::cerr << "单词数量超过数组容量 (" << maxWords << ")" << std::endl;
    }

    file.close(); // 关闭文件
    return true;
}


