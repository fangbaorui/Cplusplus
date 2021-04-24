#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
#include<string>

using namespace std;

//实现string类的接口，并完成测试，要求利用深拷贝和深赋值实现
/*class string
{
public:
	string(const char* str = "")；
		string(const string& s);
	string& operator=(const string& s);
	~string()；
private:
	char* _str;
};*/
//方法一：string的传统版实现
class string
{
public:
	//构造函数
	string(const char* str = "")
	{
		//构造string类对象，如果传递nullptr指针，认为程序非法，此处断言
		if (nullptr == str)
		{
			assert(false);
			return;
		}
		_str = new char[(strlen(str) + 1)];
		strcpy(_str, str);
	}

	//拷贝构造函数
	string(const string& s)
		:_str(new char[(strlen(s._str) + 1)])
	{
		strcpy(_str, s._str);
	}

	//赋值语句
	string& operator=(const string& s)
	{
		if (this != &s)
		{
			delete[] _str;
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
		}
		return *this;
	}

	//析构函数
	~string()
	{
		delete[] _str;
		_str = nullptr;
	}
private:
	char* _str;
};


//方法二：string的临时对象交换现代版
class string
{
public:
	//构造函数，考虑str为空的情形
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
		:_str(nullptr)
	{
		string strTmp(s._str);
		swap(_str, strTmp._str);
	}

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

	//当_str不为空是才进行释放
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