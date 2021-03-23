//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//using namespace std;
//
////函数模板
////T:模板参数
//template <typename T>
//void Swap(T& a, T& b)
//{
//	T temp = a;
//	a = b;
//	b = temp;
//}
//
////自定义类型
//struct A
//{
//	A(int a)
//		:_a(a)
//	{}
//	int _a = 1;
//};
//
//void test()
//{
//	int a = 1, b = 2;
//	char d = 'm', e = 'n';
//	double f = 1.2, g = 2.5;
//	A a1(10);
//	A a2(20);
//	Swap(a, b);
//	Swap(d, e);
//	Swap(f, g);
//
//	Swap(a1, a2);
//}
//int main()
//{
//	test();
//	return 0;
//}



//函数模板的实例化
//#include<iostream>
//using namespace std;
// template<class T>
// T Add(const T& a, const T& b)
// {
//	 return a + b;
// }
//
//void test()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.0, d2 = 20.0;
//	Add(a1, a2);
//	Add(d1, d2);
//
//	//1.用户自己来强制转化
//	Add(a1, (int)d1);
//
//	//2.使用显示实例化
//	Add<int>(a1,d1);
//}
//int main()
//{
//	test();
//	return 0;
//}



////模板参数的匹配原则
////一个非模板函数可以和一个同名的函数模板同时存在，
////而且该函数模板还可以被实例化为这个非模板函数
//
////对于非模板函数和同名函数模板，如果其他条件都相同，
////在调动时会优先调用非模板函数而不会从该模板产生出一个实例，
////如果模板可以产生一个具有更好匹配的函数，那么将选择模板
//#include<iostream>
//using namespace std;
//
////专门处理int的加法函数
//int Add(int a, int b)
//{
//	return a + b;
//}
//
////通用加法函数
//template<class T>
//T Add(T a, T b)
//{
//	return a + b;
//}
//void test()
//{
//	//与非模板函数匹配，不需要函数模板实例化
//	Add(1, 2);
//	//调用编译器特化的Add版本
//	Add<int>(1, 2);
//	//模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的Add函数
//	Add(1, 2.0);
//}
//int main()
//{
//	test();
//	return 0;
//}



#include<iostream>
using namespace std;

template <class T>
class seqList
{
public:
	seqList(int n)
		:_data(new T[n])
		, size(0)
		, capacity(n);
	{}

	T seqListAt(size_t pos);
private:
	T* _data;
	size_t size;
	size_t capacity;
};

//类外定义函数：需要加泛型声明
template <class T>
seqList<T>::seqListAt(size_t pos)
{
	return _data[pos];
}



