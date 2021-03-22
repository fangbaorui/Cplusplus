#define _CRT_SECURE_NO_WARNINGS

////经典写法
//#include<string>
//#include<iostream>
//using namespace std;
//class String
//{
//public:
//	//String()
//	//	:_data(new char[1])
//	//{
//	//	_data[0] = '\0';
//	//}
//
//	//全缺省构造函数
//	String(const char* str = "")
//		:_data(new char[strlen(str) + 1])
//	{
//		strcpy(_data, str);
//		cout << "String(char*)" << endl;
//	}
//
//
//	////浅拷贝
//	//String(const String& str)
//	//	:_data(str._data)
//	//{}
//
//
//	String(const String& str)
//		:_data(new char[strlen(str._data) + 1])
//	{
//		//深拷贝
//		strcpy(_data, str._data);
//	}
//
//
//	const char* c_str() const
//	{
//		return _data;
//	}
//
//
//	String& operator=(const String& str)
//	{
//		if (this != &str)
//		{
//			//1.释放原有的空间
//			delete[] _data;
//			//2.申请新的空间
//			_data = new char[strlen(str._data) + 1];
//			//3.拷贝内容
//			strcpy(_data, str._data);
//		}
//		return *this;
//	}
//
//
//	~String()
//	{
//		if (_data)
//		{
//			delete[] _data;
//			_data = nullptr;
//			cout << "~String()" << endl;
//		}
//	}
//
//private:
//	char* _data;
//};
//
//
//void test()
//{
//	String str("123");
//	String copy(str);
//	String str2("456");
//	String str3;
//	str2 = str;
//	str3 = str2;
//
//	//拷贝构造
//	String str4 = str;
//}
//
//
////void test()
////{
////	String str("123");
////	//浅拷贝：只拷贝的String对象的内容
////	//String copy(str);   //浅拷贝
////	String str2("456");
////	str2 = str;   //浅拷贝。内存泄漏
////};
//
//
////void test()
////{
////	String str;
////	cout << str.c_str() << endl;
////	String str2;
////	cout << str2.c_str() << endl;
////
////}
//
//int main()
//{
//	test();
//	return 0;
//}




//现代写法
#include<string>
#include<iostream>
using namespace std;
class String
{
public:

	//全缺省构造函数
	String(const char* str = "")
		:_data(new char[strlen(str) + 1])
	{
		strcpy(_data, str);
		cout << "String(char*)" << endl;
	}


	//拷贝构造现代写法
	String(const String& str)
		:_data(nullptr)
	{
		String tmp(str._data);
		strcpy(tmp._data, _data);
	}


	const char* c_str() const
	{
		return _data;
	}


	//赋值运算符的现代写法
	//释放原有空间，申请新的空间，拷贝内容
	String& operator=(String str)
	{
		swap(str._data, _data);
		return *this;
	}


	//String& operator=(const String& str)
	//{
	//	if (this != &str)
	//	{
	//		//1.释放原有的空间
	//		delete[] _data;
	//		//2.申请新的空间
	//		_data = new char[strlen(str._data) + 1];
	//		//3.拷贝内容
	//		strcpy(_data, str._data);
	//	}
	//	return *this;
	//}


	~String()
	{
		if (_data)
		{
			delete[] _data;
			_data = nullptr;
			cout << "~String()" << endl;
		}
	}

private:
	char* _data;
};


void test()
{
	String str("123");
	String copy(str);
}



int main()
{
	test();
	return 0;
}