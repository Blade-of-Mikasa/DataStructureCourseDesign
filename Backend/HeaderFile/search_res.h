#pragma once
#include<bits/stdc++.h>
#include "Myword.h"
using namespace std;
class SearchRes {
public:
    /*
        visit_by_index: 0: 按索引访问, 1: 按值访问
        success_search: 0: 搜索失败, 1: 搜索成功
        index: 搜索结果的索引, 如果visit_by_index为0, 则为索引, 如果visit_by_index为1, 则为值
        search_len: 搜索长度
        word: 搜索结果的单词, 如果visit_by_index为1, 则为单词
    */
    bool visit_by_index, success_search;
    int index, search_len;
    Myword word;
    SearchRes() {
        visit_by_index = false;
        success_search = false;
        index = -1;
        search_len = 0;
    }
    
    SearchRes(int index, int search_len, bool visit_by_index, bool success_search) {
        this->index = index;
        this->search_len = search_len;
        this->visit_by_index = visit_by_index;
        this->success_search = success_search;
    }
    SearchRes(Myword word, int search_len, bool visit_by_index, bool success_search) {
        this->word = word;
        this->search_len = search_len;
        this->visit_by_index = visit_by_index;
        this->success_search = success_search;
    }
    SearchRes(Myword word, int index, int search_len, bool visit_by_index, bool success_search)
    {
        this->word = word;
        this->index = index;
        this->search_len = search_len;
        this->visit_by_index = visit_by_index;
        this->success_search = success_search;
    }

    // 重载输出运算符
    friend ostream& operator<<(ostream& os, const SearchRes& find_information)
    {
        if(find_information.success_search == 1)
        {
            cout<<"查找成功: "<<find_information.word<<endl;
            if(find_information.visit_by_index)
                cout<<"索引: "<<find_information.index<<endl;
            else
                cout<<"不可通过索引访问"<<endl;
        }
        else
            cout<<"查找失败"<<find_information.word<<endl;
        cout<<"查找长度: "<<find_information.search_len<<endl;
        return os;
    }
};