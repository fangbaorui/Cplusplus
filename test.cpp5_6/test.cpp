#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//���󣺰������麯��
//�����ࣺ����ʵ����
class A
{
public:
	//���麯���������ӿ�=0
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
	//A a;  //ֻ��b c ����ʵ��������
	B b;
	C c;
	//D d;
}



//ʵ�ֶ�̬
//0.ǰ�᣺�̳�
//1.�麯��
//2.�����麯�������ͱ�����ָ��������
//3.�麯����Ҫ����д
//4.һ����ͨ�������ָ��������õ����麯��

//final�����ࣺ1.���� final---�����಻�ܱ��̳�
//2.final�����麯�������麯�����ܱ�������д������ʵ�ּ̳�
//class A1 final
//{};
//class B1��public A1
//{};

//class A
//{};
//class B :public A
//{};
//
//class Person
//{
//public:
//	//�麯����virtual+����
//	virtual void buyTicket()
//	{
//		cout << "ȫ��" << endl;
//	}
//
//	virtual A* hongbao()
//	{
//		cout << "1ëǮ" << endl;
//		return new A;
//	}
//
//	//һ�����������������麯����������̬��Ϊ����֤��Դ�������ͷ�
//	virtual ~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//
//	//2.final�����麯�������麯�����ܱ�������д��
//	//final:����ʵ�ּ̳�,�������޸ļ̳�
//	virtual void fun() final
//	{}
//};
//
//class Student :public Person
//{
//public:
//	//�麯����д��
//	//1.�������������б�����ֵ�͸����麯����ȫ��ͬ
//	
//	//virtual����ʡ�ԣ���̳и���
//
//	//override����麯���Ƿ���д�˸����ĳһ���麯����ǿ����д
//	//override:��д���ݣ����ֽӿڣ�����ֵ���������������б��̳У����̳�ʵ�֣�����ʵ��
//	virtual void buyTicket() override
//	{
//		cout << "���" << endl;
//	}
//
//	//Э�䣺����ֵ���Բ���ͬһ�����ͣ����Ǳ������м̳й�ϵ��ָ���������
//	virtual B* hongbao()
//	{
//		cout << "100��" << endl;
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

////�Ƕ�̬��������
//void fun0(Person rp)
//{
//	rp.buyTicket();
//}
//
////��̬��������
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