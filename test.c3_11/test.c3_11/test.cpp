#define _CRT_SECURE_NO_WARNINGS
////������룬C�����У��ṹ����ֻ�ܶ����������C++�У��ṹ���ڲ������Զ��������Ҳ���Զ��庯��
//#include<iostream>
//using namespace std;
//struct Student
//{
//    void SetStudentInof(const char* name, const char* gender, int age)
//    {
//        strcpy(_name, name);
//        strcpy(_gender, gender);
//        _age = age;
//    }
//
//    void PrintStudentInof()
//    {
//        cout << _name << " " << _gender << " " << _age << endl;
//    }
//
//    char _name[20];
//    char _gender[3];
//    int _age;
//};
//int main()
//{
//    Student s;
//    s.SetStudentInof("Perer", "��",18);
//    s.PrintStudentInof();
//    cout << s._gender << endl;
//    return 0;
//}




////��Ķ���
////1.�����Ͷ���ȫ�����������У���Ҫע�⣺��Ա������������ж��壬���������ܻὫ�䵱��������������
//class Person
//{
//public:
//	void showInof()
//	{
//		cout << _name << "-" << _sex << "-" << _age << endl;
//	}
//public:
//	char* _name;
//	char* _sex;
//	int _age;
//};



////2.��������.h�ļ��У���Ķ������.cpp�ļ���
////����������ʵ���ļ�person.cpp��
//#include"person.h"
//void Person::showInfo()
//{
//	cout << _name << "-" << _sex<<"-" << _age << endl;
//}



//���������
//�ඨ����һ���µ�������������г�Ա��������������С�
//�������ⶨ���Ա����Ҫʹ�ã��������������ָ����Ա�����ĸ�����

//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	void PrintPersonInfo();
//private:
//	char _name[20];
//	char _gender[3];
//	int _age;
//};
//
////������Ҫָ��PrintPersonInfo������Person�������
//void Person::PrintPersonInfo()
//{
//	cout << _name << " " << _gender << " " << _age << endl;
//}



//#include<iostream>
//using namespace std;
//class A {
//public:
//	void PrintA
//	{
//		cout << _a << endl;
//	}
//private:
//	char _a;
//};


// ���м��г�Ա���������г�Ա����
class A1 {
public:
	void f1() {}
private:
	int _a;
};
// ���н��г�Ա����
class A2 {
public:
	void f2() {}
};
// ����ʲô��û��---����
class A3
{};