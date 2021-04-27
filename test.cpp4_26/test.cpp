#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


////友元关系不能继承，也就是说基类友元不能访问子类私有和保护成员
//class Student;
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // 姓名
//};
//class Student : public Person
//{
//protected:
//	int _stuNum; // 学号
//};
//void Display(const Person& p, const Student& s) {
//	//不能访问
//	//cout << p._name << endl;
//	//cout << s._stuNum << endl;
//}
//void main()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//}




////基类的静态成员在整个继承体系中被所有对象共享
//class A
//{
//public:
//	A()
//	{
//		++_a;
//	}
//public:
//	static int _a;
//};
//
//int A::_a = 0;
//
//class B :public A
//{};
////多继承
//class C:public B,public A  
//{};
//
//void test()
//{
//	A a;
//	B b;
//	C c;
//	cout << a._a << endl;
//	cout << b._a << endl;
//	cout << c._a << endl;
//	cout << &a._a << endl;
//	cout << &b._a << endl;
//}




//class Person
//{
//public:
//	string _name; // 姓名
//};
//class Student : public Person
//{
//protected:
//	int _num; //学号
//};
//class Teacher :  public Person
//{
//protected:
//	int _id; // 职工编号
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//
//void test()
//{
//	cout << sizeof(string) << endl;  //28
//	cout << sizeof(Assistant) << endl; //92
//
//	Assistant a;
//	//a._name = "1234"; 指代不明确
//	//菱形继承的问题：数据冗余，二义性--》通过菱形虚拟继承解决
//	a.Student::_name = "1";
//	a.Teacher::_name = "2";
//}


//class Person
//{
//public:
//	string _name; // 姓名
//};
////虚拟继承：virtual 继承方式 父类名称
//class Student : virtual public Person
//{
//protected:
//	int _num; //学号
//};
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // 职工编号
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//
//void test()
//{
//	cout << sizeof(string) << endl;  //28
//	cout << sizeof(Assistant) << endl; //菱形虚拟继承后72
//
//	Assistant a;
//	//菱形继承的问题：数据冗余，二义性--》通过菱形虚拟继承解决
//	a.Student::_name = "1";
//	a.Teacher::_name = "2";
//
//	a._name = "1234";
//}


struct A
{
	int _a;
};
struct B :public A
{
	int _b;
};
struct C :public A
{
	int _c;
};
struct D :public B, public C
{
	int _d;
};
void test()
{
	D d;
	d.B::_a = 1;
	d._b = 2;
	d.C::_a = 3;
	d._c = 4;
	d._d = 5;
}


int main()
{
	test();
	return 0;
}