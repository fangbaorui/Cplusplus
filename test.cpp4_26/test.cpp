#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


////��Ԫ��ϵ���ܼ̳У�Ҳ����˵������Ԫ���ܷ�������˽�кͱ�����Ա
//class Student;
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // ����
//};
//class Student : public Person
//{
//protected:
//	int _stuNum; // ѧ��
//};
//void Display(const Person& p, const Student& s) {
//	//���ܷ���
//	//cout << p._name << endl;
//	//cout << s._stuNum << endl;
//}
//void main()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//}




////����ľ�̬��Ա�������̳���ϵ�б����ж�����
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
////��̳�
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
//	string _name; // ����
//};
//class Student : public Person
//{
//protected:
//	int _num; //ѧ��
//};
//class Teacher :  public Person
//{
//protected:
//	int _id; // ְ�����
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // ���޿γ�
//};
//
//void test()
//{
//	cout << sizeof(string) << endl;  //28
//	cout << sizeof(Assistant) << endl; //92
//
//	Assistant a;
//	//a._name = "1234"; ָ������ȷ
//	//���μ̳е����⣺�������࣬������--��ͨ����������̳н��
//	a.Student::_name = "1";
//	a.Teacher::_name = "2";
//}


//class Person
//{
//public:
//	string _name; // ����
//};
////����̳У�virtual �̳з�ʽ ��������
//class Student : virtual public Person
//{
//protected:
//	int _num; //ѧ��
//};
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // ְ�����
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // ���޿γ�
//};
//
//void test()
//{
//	cout << sizeof(string) << endl;  //28
//	cout << sizeof(Assistant) << endl; //��������̳к�72
//
//	Assistant a;
//	//���μ̳е����⣺�������࣬������--��ͨ����������̳н��
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