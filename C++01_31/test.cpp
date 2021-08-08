#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//内联函数
inline int add(int a, int b)
{
	return a + b;
}
int Add(int a, int b)
{
	return a + b;
}
int main()
{
	int a = add(10, 20);  //实际编译时不调用函数，a=10+20,用函数体替换函数调用
	int b = Add(10, 20);//进行函数调用
	return 0;
}


//链接错误，无法解析的外部符号 "void __cdecl f(int)" (?f@@YAXH@Z)，函数 _main 中引用了该符号
#include"F.h"
int main()
{
	f(10);
	return 0;
}


// F.h
#include <iostream>
using namespace std;
inline void f(int i);
// F.cpp
#include "F.h"
void f(int i) {
	cout << i << endl;
}
// main.cpp
#include "F.h"
int main()
{
	f(10);
	return 0;
}
// 链接错误：main.obj : error LNK2019: 无法解析的外部符号 "void __cdecl f(int)" 
//(?f@@YAXH@Z)，该符号在函数_main中被引用。



#include<iostream>
using namespace std;
//auto自动类型推导
void test()
{
	//auto：自动类型推导
	auto a = 10;
	auto b = 2.0;
	auto c = 'a';
	auto d = 'a' + b;
	cout << typeid(a).name() << endl; //int
	cout << typeid(b).name() << endl; //double
	cout << typeid(c).name() << endl; //char
	cout << typeid(d).name() << endl; //double
	//auto e;无法编译，使用auto定义变量时必须对其进行初始化
}



void test()
{
	int a = 10;
	int b = a;
	int& ra = a;

	//定义指针：*可加可不加
	auto pa = &a;
	auto* pb = &b;

	//定义引用：必须加&
	auto rb = a;
	auto c = b; //不是引用

	cout << typeid(pa).name() << endl; //int*
	cout << typeid(pb).name() << endl; //int*
	cout << typeid(ra).name() << endl; //int
	cout << typeid(c).name() << endl;  //int

	rb = 5; //ra是引用a=ra=5
	c = 100; //c不是引用

	int d, e, f;
	//一行定义多个变量时，表达式推导出的类型必须一致
	//auto g = 20, h = 20, k = 2.0;
}



//范围for
void test()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		cout << arr[i] << " ";
	}  //1 2 3 4 5 6 7 8 9
	cout << endl;

	//范围for： 当前的数据：循环的范围
	for (int e : arr)
	{
		cout << e << " ";
	}   //1 2 3 4 5 6 7 8 9
	cout << endl;

	for (const auto& e : arr)
	{
		cout << e << " ";
	}   //1 2 3 4 5 6 7 8 9
	cout << endl;

	for (int a : arr)
	{
		a = 10;
		cout << a << " ";
	}  //10 10 10 10 10 10 10 10 10
	cout << endl;

	for (int& a : arr)
	{
		a = 10;
		cout << a << " ";
	}  //10 10 10 10 10 10 10 10 10
	cout << endl;
}


void TestFor()
{
	int array[] = { 1, 2, 3, 4, 5 };
	for (auto& e : array)
		e *= 2;

	for (auto e : array)
		cout << e << " ";

}

void f(int) {
	cout << "f(int)" << endl;
}
void f(int*) {
	cout << "f(int*)" << endl;
}
int main()
{
	f(0);
	f(NULL);
	f((int*)NULL);
	return 0;
}



int main()
{
	test();
	return 0;
}