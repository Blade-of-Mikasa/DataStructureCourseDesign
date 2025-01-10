#include<iostream>
#include<string>
#include "../HeaderFile/all_header.h"
using namespace std;


int unique_by_traverse(string str[], Myword w[], int size)
{
    //将str中的所有单词存入w中, 去重并且统计频率
    int n = 0;
    for(int i = 0; i < size; i++)
    {
        if(str[i].empty())
            continue;
        bool flag = false;
        for(int j = 0; j < n; j++)
        {
            if(str[i] == w[j].str)
            {
                w[j].freq++;
                flag = true;
                break;
            }
        }
        if(!flag)//如果没有找到相同的单词
        {
            w[n].str = str[i];
            w[n].freq = 1;
            n++;
        }
    }
    //返回w的长度
    return n;
}

void unique_by_sort(string str[], Myword w[])
{
    //将str中的所有单词存入w中, 去重并且统计频率
    int n = 0;
    for(int i = 0;!str[i].empty(); i++)
    {
        w[n].str = str[i];
        w[n].freq = 1;
        n++;
    }
    //对w进行排序
    QuickSort(w, 0, n - 1);
    //去重
    int m = 0;
    for(int i = 0; i < n; i++)
    {
        if(w[i].str != w[i + 1].str)
        {
            w[m].str = w[i].str;
            w[m].freq = w[i].freq;
            m++;
        }
    }
}

