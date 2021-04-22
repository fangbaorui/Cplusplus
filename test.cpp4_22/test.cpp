#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<array>
using namespace std;

//类模板特化，应用场景：类型萃取
//前提：已有一个通用的模板
template <class T1,class T2>
struct D
{
	D(const T1& d1,const T2& d2)
		:_d1(d1)
		,_d2(d2)
	{
		cout << "D(T1,T2)" << endl;
	}
	T1 _d1;
	T2 _d2;
};

//特化:全特化：所有的类型都是具体类型
template <>
struct D<char, double>
{
	D(const char& d1, const double& d2)
		:_d1(d1)
		, _d2(d2)
	{
		cout << "D(char,double)" << endl;
	}
	char _d1;
	double _d2;
};

//偏特化：：1.只特化部分类型
template <class T1>
struct D<T1,char>
{
	D(const T1& d1, const double& d2)
		:_d1(d1)
		, _d2(d2)
	{
		cout << "D(T1,char)" << endl;
	}
	T1 _d1;
	double _d2;
};
//偏特化：2.给模板参数做进一步的限制
template <class T1,class T2>
struct D<T1* ,T2*>
{
public:
	D(const T1& d1, const T2& d2)
		:_d1(d1)
		, _d2(d2)
	{
		cout << "D(T1*,T2*)" << endl;
	}
	T1 _d1;
	T2 _d2;
};


//void test()
//{
//	D<int, int> d(1,1); //通用模板的实例化
//	D<char,double> d2('a', 1.1); //全特化模板的实例化
//	D<int, char> d3(1, 'a'); //偏特化模板实例化
//	D<int*, int*> d4(1, 2); //偏特化模板实例化
//
//}




//函数模板特化
template <class T>
bool isEqual(T& a, T& b)
{
	return a == b;
}

bool isEqual(char* a, char* b)
{
	return 0 == strcmp(a, b);
}

//template<>
//bool isEqual<char*>(char*& a, char*& b)
//{
//	return 0 == strcmp(a, b);
//}
//void test()
//{
//	int a = 1;
//	int b = 1;
//	int* pa = &a;
//	int* pa2 = &a;
//	bool ret = isEqual(a, b);
//	ret = isEqual(pa, pa2);
//
//	char* ptr1 = "1234";
//	char* ptr2 = "1234";
//	ret = isEqual(ptr1, ptr2);
//
//	char ptr3[] = "1234";
//	char ptr4[] = "1234";
//	ret = isEqual(ptr3, ptr4);
//}


//void test()
//{
//	array<int, 20> a;
//}

int main()
{
	test();
	return 0;
}