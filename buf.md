把下面的代码封装好:

相关信息: 

```cpp
class Myword{
public:
    std::string str = "";
    int freq 
    = 0;
    //...
}
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
    //...
}
Myword target = {"practices", 0};
SearchRes find_information;
int cnt = 1000;
int Time = 0;
```

代码:

```cpp 
    {
        // 多次查找
        Time = 0;
        while (cnt--)
        {
            Time += measureTime([&]()
                                { search_in_linear_structure(slist, slist.getSize(), target); });
        }
        cout << "线性查找时间:" << Time / CLOCKS_PER_SEC / cnt << endl;

        Time = 0;
        for (int i = 0; i < size; ++i)
        {
            Time += measureTime([&]()
                                { search_in_linear_structure(slist, slist.getSize(), warr[i]); });
        }
        cout << "线性查找平均查找时间:" << Time / CLOCKS_PER_SEC / size << endl;

        ASL = 0;
        for (int i = 0; i < size; ++i)
        {
            find_information = search_in_linear_structure(slist, slist.getSize(), warr[i]);
            ASL += find_information.search_len;
        }
        cout << "线性查找平均查找长度:" << ASL / size << endl;

        // // 线性查找
        // find_information = search_in_linear_structure(slist, slist.getSize(), target);
        // // output_search_information(find_information);
        // cout << "线性查找:" << endl;
        // cout<<find_information<<endl;
    }
```