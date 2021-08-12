#include<iostream>
#include<assert.h>
using namespace std;
/*方法一: string的传统版实现*/
class string
{
public:
    //构造函数
    string(const char* str = "")
    {
        // 构造string类对象时，如果传递nullptr指针，认为程序非法，此处断言下
        if (nullptr == str)
        {
            assert(false);
            return;
        }
        _str = new char[strlen(str) + 1];
        strcpy(_str, str);
    }

    //拷贝构造函数
    string(const string& s)
        : _str(new char[strlen(s._str) + 1])
    {
        strcpy(_str, s._str);
    }

    //赋值语句 初级阶段的实现，如果考虑异常安全，可以参考剑指offer一书的面试题1
    string& operator=(const string& s)
    {
        if (this != &s)
        {
            delete[]_str;
            _str = new char[strlen(s._str) + 1];
            strcpy(_str, s._str);
        }
        return *this;
    }

    //析构函数
    ~string()
    {
        delete[]_str;
        _str = nullptr;
    }
private:
    char* _str;
};


/*方法二: String的临时对象交换现代版*/
class string
{
public:
    //构造函数 考虑str为空的情形
    string(const char* str = "")
    {
        if (nullptr == str)
            str = "";
        _str = new char[strlen(str) + 1];
        strcpy(_str, str);
    }

    //拷贝构造函数 通过临时对象的交换方式进行拷贝构造，构造对象借助之前实现的普通构造函数来构造   
    //对象,然后通过交换对象的内部指针的指向，从而达到拷贝构造对象，好处就是如果出错，其根本就是  
    //构造函数的错误，我们相当于把错误最终归结为构造函数
    string(const string& s)
        : _str(nullptr)
    {
        string strTmp(s._str);
        swap(_str, strTmp._str);
    }

    //赋值语句 通过临时对象的交换方式进行实现，
    //如果考虑异常安全，可以参考剑指offer一书的面试题1
    //这种交换方式在赋值语句中，有利于预防内存泄漏，因为交换完成的临时对象，一旦生存作用域结   
    //束，就会自动调用其析构函数，释放对应的资源
    string& operator=(const string& s)
    {
        if (this != &s)
        {
            string strTmp(s);
            swap(_str, strTmp._str);
        }
        return *this;
    }

    //析构函数,当_str不为空时才进行释放工作并且以数组方式进行释放
    ~string()
    {
        if (_str)
        {
            delete[] _str;
            _str = nullptr;
        }
    }
private:
    char* _str;
};