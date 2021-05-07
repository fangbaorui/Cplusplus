#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//抽象：包含纯虚函数
//抽象类：不能实例化
class A
{
public:
	//纯虚函数：函数接口=0
	virtual void fun() = 0;
};
class B :public A
{
public:
	virtual void fun()
	{
		cout << "B::fun()" << endl;
	}
};
class C :public A
{
public:
	virtual void fun()
	{
		cout << "C::fun()" << endl;
	}
};
class D :public A
{};
void test()
{
	//A a;  //只有b c 才能实例化对象
	B b;
	C c;
	//D d;
}



//实现多态
//0.前提：继承
//1.虚函数
//2.调用虚函数的类型必须是指针是引用
//3.虚函数需要被重写
//4.一般是通过父类的指针或者引用调用虚函数

//final修饰类：1.类名 final---》此类不能被继承
//2.final修饰虚函数：此虚函数不能被子类重写，体现实现继承
//class A1 final
//{};
//class B1：public A1
//{};

//class A
//{};
//class B :public A
//{};
//
//class Person
//{
//public:
//	//虚函数：virtual+函数
//	virtual void buyTicket()
//	{
//		cout << "全价" << endl;
//	}
//
//	virtual A* hongbao()
//	{
//		cout << "1毛钱" << endl;
//		return new A;
//	}
//
//	//一般把析构函数定义成虚函数，产生多态行为，保证资源被正常释放
//	virtual ~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//
//	//2.final修饰虚函数：此虚函数不能被子类重写，
//	//final:体现实现继承,不能再修改继承
//	virtual void fun() final
//	{}
//};
//
//class Student :public Person
//{
//public:
//	//虚函数重写：
//	//1.函数名，参数列表，返回值和父类虚函数完全相同
//	
//	//virtual可以省略，会继承父类
//
//	//override：检查函数是否重写了父类的某一个虚函数，强制重写
//	//override:重写内容，体现接口（返回值，函数名，参数列表）继承，不继承实现，重新实现
//	virtual void buyTicket() override
//	{
//		cout << "半价" << endl;
//	}
//
//	//协变：返回值可以不是同一个类型，但是必须是有继承关系的指针或者引用
//	virtual B* hongbao()
//	{
//		cout << "100快" << endl;
//		return new B;
//	}
//
//	virtual ~Student()
//	{
//		if (_name)
//		{
//			delete[] _name;
//			cout << "delete[] _name" << endl;
//		}
//		cout << "~Student()" << endl;
//	}
//
//	//virtual void fun()
//	//{}
//
//private:
//	char* _name = new char[100];
//};
//
//void test()
//{
//	Person* ps = new Student;
//	delete ps;
//
//	ps = new Person;
//	delete ps;
//}

////非多态：看类型
//void fun0(Person rp)
//{
//	rp.buyTicket();
//}
//
////多态：看对象
//void fun(Person& rp)
//{
//	rp.buyTicket();
//}
//
//void fun2(Person& rp)
//{
//	rp.hongbao();
//}
//void test()
//{
//	Person p;
//	Student stu;
//	fun0(p);
//	fun0(stu);
//
//	fun(p);
//	fun(stu);
//
//	fun2(p);
//	fun2(stu);
//}

//void test()
//{
//	Person p;
//	Person& rp = p;
//	Person* pp = &p;
//	rp.buyTicket();
//	pp->buyTicket();
//}


int main()
{
	test();
	return 0;
}