#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	//Person(int id=1, int age=2)
	Person(int id,int age)
		:_id(id)
		,_age(age)
	{
		cout << "Person(int,int)" << endl;
	}

	Person(const Person& p)
		:_id(p._id)
		, _age(p._age)
	{
		cout << "Person(const Preson&)" << endl;
	}

	Person& operator=(const Person& p)
	{
		if (this != &p)
		{
			_id = p._id;
			_age = p._age;
		}
		cout << "Person& operator=(const Person)" << endl;
		return *this;
	}

	~Person()
	{
		cout << "~Person" << endl;
	}
protected:
	int _id;
	int _age;
};

class Student :public Person
{
public:
	//����ĳ�ʼ���б��в���ֱ�ӳ�ʼ�������Ա
	//����ĳ�Ա��Ҫ���ø��๹����ɳ�ʼ��
	//���������Ĭ�Ϲ��죬��ʼ���б��п��Բ�����ʾ���ø���Ĺ��캯�������������Զ����ø����Ĭ�Ϲ���
	//�������û��Ĭ�Ϲ��죬������ʾ���ø����һ�����캯��
	Student(int id,int age,int stuId)  
		:Person(id,age)    //��Ա�ĳ�ʼ��˳��һ�����ȳ�ʼ�����࣬�ڳ�ʼ�������¶���ĳ�Ա
		,_stuId(stuId)
	{
		cout << "Student(int,int,int)" << endl;
	}

	//��������ĳ�ʼ���б��п��Ե�����ͨ�ĸ��๹�캯��
	//Ҳ���Ե��ÿ�������
	Student(const Student& stu)
		:Person(stu)
		,_stuId(stu._stuId)
	{}

	
	Student& operator=(const Student& stu)
	{
		if (this != &stu)
		{
			//_id = stu._id;
			//_age = stu._age;
			//����ĸ�ֵ������ĸ�ֵ���������ͬ�����أ���Ҫ���ϸ���������
			Person::operator=(stu);

			_stuId = stu._stuId;
		}
		cout << "Student& operator=(const Student& stu)" << endl;
		return *this;
	}

	//���������ײ�ĺ�������ͬ��destructor
	//���������͸���������ͬ������
	//���������κ�����¶����Զ����ø��������������Ҫ��ʾ���ø�������
	~Student()
	{
		//~Person();  //����
		//Person::~Person();
		cout << "~Student()"<<endl;
	}
private:
	int _stuId;
};

void test()
{
	////�����Ĭ�Ϲ�����Զ����ø���Ĺ��캯��
	////Student stu;
	//Student stu(1, 2, 3);

	////�����Ĭ�Ͽ��������Զ����ø���Ŀ�������
	////���������ʾ�����˿������죬����Ŀ���������Զ����ø����Ĭ�Ϲ���
	//Student copy(stu);

	////��ֵ�������Ĭ�ϸ�ֵ��������Զ����ø���ĸ�ֵ�����
	////���ඨ��ĸ�ֵ����������Զ����ø���ĸ�ֵ�������������ʾ����
	//stu = copy;

	//�����Ĭ������������ʾ��������������Զ����ø����Ĭ������
	Student stu(1, 2, 3);
}





//class A
//{
//public:
//	void fun()
//	{
//		cout << "A::fun()" << endl;
//	}
//protected:
//	int _a = 1;
//};
//
//class B : public A
//{
//public:
//	//ͬ�����أ������ǳ�Ա�������ǳ�Ա������ֻҪ��Ա������ͬ���ͻṹ��ͬ������
//	void fun()
//	{
//		cout << "B::fun()" << endl;
//	}
//
//	void printB()
//	{
//		cout << _a << endl;
//		//ͬ�����ظ���ĳ�Ա����������ͨ�����ϸ�������������
//		cout << A::_a << endl;
//	}
//private:
//	int _a = 100;
//};
//
//void test()
//{
//	//�̳е�_a�������б�������
//	B b;
//	b.printB();
//	//����������������������ͬ�ĺ������ͻṹ��ͬ������
//	b.fun();
//	//�����Ҫ���ʸ����ͬ����������Ҫ���ϸ���������
//	b.A::fun();
//}




//class Person
//{
//public:
//	void Pring()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _name = "peter";  //string��С��28
//	int _age = 10;
//private:
//	int _id = 10;
//};
//
//class A
//{};
//
////class ������࣬Ĭ�ϼ̳з�ʽ��private
////˽�м̳У������е����г�Ա�����������private��Ա���ɼ���������Ա�ķ���Ȩ�������ⲻ�ɼ�
////class student:Person
////���м̳У����������private��Ա���ɼ�û������Ա��Ȩ�޲��ᷢ���仯
//class student : public Person
//{
//	void printStu()
//	{
//		//protected��Ա�������пɼ������ⲻ�ɼ�
//		cout << _age << _name << endl;
//		//�����˽�г�Ա������̳У��������಻�ܷ��ʸ����˽�г�Ա
//		//cout << _id << endl;
//	}
//private:
//	int _stuId = 20;
//};
//
//class C : public student
//{
//	void fun()
//	{
//		//cout << _age << _name << endl;
//	}
//};
//
////void test()
////{
////	cout << sizeof(Person) << endl;  
////	cout << sizeof(A) << endl;  
////	cout << sizeof(student) << endl;  
////}
//
//
//void test()
//{
//	student s;
//	Person p;
//	//��Ƭ:����������ã�ָ�븳�������Ӧ�Ķ������ã�ָ��
//	p = s;
//	Person& rs = s;   //ֻ���������
//	Person* ps = &s;   //ֻ���������
//
//	student rs2 = s;
//	student* ps2 = (student*) ps;   //���������
//
//	//1.��������ܸ�ֵ���������,ǿ������ת��Ҳ����
//	//2.�������ã�ָ�벻��ֱ�Ӹ�ֵ����������ã�ָ�룬���ǿ���ͨ��ǿ������ת����ֵ
//	//���������ǿ������ת������Ϊ���ܻ��������Խ�������
//	student& rp = (student&)rs;
//	student* pp = (student*)&p;
//}


int main()
{
	test();
	return 0;
}