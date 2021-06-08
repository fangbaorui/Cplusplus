#include<iostream>
#include<stdlib.h>
using namespace std;


class B
{
public:
	virtual void fun(){}
};
class C:public B
{};
void test()
{
	int a = 10;
	double f = 1.2;
	//隐式类型转换
	a = (int)f;//有没有(int),都能转换

	int* pa = &a;
	//强制类型转换
	a = (int)pa;

	int* p=(int*)malloc(4);

	//C++类型转换：
	//1.static_cast:支持所有的隐式类型转换
	a = static_cast<int>(f);
	//特殊：支持父类指针/引用到子类指针/引用的转换
	B* pb = new B;
	C* pc = (C*)pb;
	C* pc2 = static_cast<C*>(pb);
	//不支持其他强制类型转换
	//a = static_cast<int>(pa);


	//2.reinterpret_cast:支持强制类型转换
	a = reinterpret_cast<int>(pa);

	//3.const_cast:去除变量的const属性
	volatile const int c = 10;
	cout << "C addr:" << &c << endl;
	cout << "C:" << c << endl;
	int* pc3 = const_cast<int*>(&c);
	cout << "C addr:" <<pc3 << endl;
	*pc3 = 20;
	cout << "C:" << c << endl;
	//20,编译器有问题，需要加个volatile关键字


	//4.dynamic_cast:只用于多态场景下的父类引用/指针向子类引用指针转换
	//dynamic_cast:会检查是否安全，只有安全，才会转换成功，不安全，返回nullptr
	B* pb2 = new B;
	C* pc4 = dynamic_cast<C*>(pb2);//转换失败
	C* pc5 = static_cast<C*>(pb2);
	cout << pc4 << endl;
	cout << pc5 << endl;

	B* pb3 = new C;
	pc4 = dynamic_cast<C*>(pb3);
	pc5 = static_cast<C*>(pb3); //不安全
	cout << pc4 << endl;
	cout << pc5 << endl;
}

int main()
{
	test();
	return 0;
}