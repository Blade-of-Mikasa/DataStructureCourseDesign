#include<iostream>
#include<string>
#include "../../HeaderFile/all_header.h"
using namespace std;

bool regularize(string str[], int size){
    string buf;
    for(int i = 0; i < size ; i++){
        // 全是数字要特判
        bool all_num = true;
        for(int j = 0; j < str[i].length(); j++){
            if(str[i][j] < '0' || str[i][j] > '9'){
                all_num = false;
                break;
            }
        }

        for(int j = 0; j < str[i].length(); j++){
            if((str[i][j] >= 'a' && str[i][j] <= 'z'))
                buf += str[i][j];            
            else if(str[i][j] >= 'A' && str[i][j] <= 'Z')
                buf += str[i][j] + 32;
            else if(str[i][j] == '-')
            {
                if(buf.empty())    continue;
                else    buf += str[i][j];
            }
            else if(j > 1 && buf.back() == '-')
                buf.pop_back();
            else    continue;
        }
        // if(all_num)
        // {
        //     debug2(str[i], buf.empty());
        // }
        str[i] = buf;
        buf.clear();
    }
    return true;
}

