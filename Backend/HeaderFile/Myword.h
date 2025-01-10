#pragma once
#include<string>

class Myword{
public:
    std::string str = "";
    int freq = 0;

    bool operator<(const Myword& w) const{
        if(str == w.str)
            return freq > w.freq;
        return str < w.str;
    }

    bool operator>(const Myword& w) const{
        if(str == w.str)
            return freq > w.freq;   
        return str > w.str;
    }

    bool operator<=(const Myword& w) const{
        if(str == w.str)
            return freq >= w.freq;
        return str < w.str;
    }

    bool operator>=(const Myword& w) const{
        if(str == w.str)
            return freq >= w.freq; 
        return str > w.str;
    }

    bool operator==(const Myword& w) const{
        return str == w.str;
    }
    bool operator!=(const Myword& w) const{
        return str != w.str;
    }

    // 重载输出运算符
    friend std::ostream& operator<<(std::ostream& os, const Myword& w) {
        os << w.str << "    " << w.freq;
        return os;
    }
};