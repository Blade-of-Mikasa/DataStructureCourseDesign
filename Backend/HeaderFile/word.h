#include<string>

class word{
public:
    std::string str = "";
    int freq = 0;

    bool operator<(const word& w) const{
        return str < w.str;
    }

    bool operator>(const word& w) const{
        return str > w.str;
    }

    bool operator==(const word& w) const{
        return str == w.str;
    }

    bool operator!=(const word& w) const{
        return str != w.str;
    }

    bool operator<=(const word& w) const{
        return str <= w.str;
    }

    bool operator>=(const word& w) const{
        return str >= w.str;
    }

    // 重载输出运算符
    friend std::ostream& operator<<(std::ostream& os, const word& w) {
        os << w.str << "    " << w.freq;
        return os;
    }
}