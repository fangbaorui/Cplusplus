#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//��������
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
	int a = add(10, 20);  //ʵ�ʱ���ʱ�����ú�����a=10+20,�ú������滻��������
	int b = Add(10, 20);//���к�������
	return 0;
}


//���Ӵ����޷��������ⲿ���� "void __cdecl f(int)" (?f@@YAXH@Z)������ _main �������˸÷���
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
// ���Ӵ���main.obj : error LNK2019: �޷��������ⲿ���� "void __cdecl f(int)" 
//(?f@@YAXH@Z)���÷����ں���_main�б����á�



#include<iostream>
using namespace std;
//auto�Զ������Ƶ�
void test()
{
	//auto���Զ������Ƶ�
	auto a = 10;
	auto b = 2.0;
	auto c = 'a';
	auto d = 'a' + b;
	cout << typeid(a).name() << endl; //int
	cout << typeid(b).name() << endl; //double
	cout << typeid(c).name() << endl; //char
	cout << typeid(d).name() << endl; //double
	//auto e;�޷����룬ʹ��auto�������ʱ���������г�ʼ��
}



void test()
{
	int a = 10;
	int b = a;
	int& ra = a;

	//����ָ�룺*�ɼӿɲ���
	auto pa = &a;
	auto* pb = &b;

	//�������ã������&
	auto rb = a;
	auto c = b; //��������

	cout << typeid(pa).name() << endl; //int*
	cout << typeid(pb).name() << endl; //int*
	cout << typeid(ra).name() << endl; //int
	cout << typeid(c).name() << endl;  //int

	rb = 5; //ra������a=ra=5
	c = 100; //c��������

	int d, e, f;
	//һ�ж���������ʱ�����ʽ�Ƶ��������ͱ���һ��
	//auto g = 20, h = 20, k = 2.0;
}



//��Χfor
void test()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		cout << arr[i] << " ";
	}  //1 2 3 4 5 6 7 8 9
	cout << endl;

	//��Χfor�� ��ǰ�����ݣ�ѭ���ķ�Χ
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