#define _CRT_SECURE_NO_WARNINGS
////类的引入，C语言中，结构体中只能定义变量，在C++中，结构体内不仅可以定义变量，也可以定义函数
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
//    s.SetStudentInof("Perer", "男",18);
//    s.PrintStudentInof();
//    cout << s._gender << endl;
//    return 0;
//}




////类的定义
////1.声明和定义全部放在类体中，需要注意：成员函数如果在类中定义，编译器可能会将其当成内联函数处理
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



////2.声明放在.h文件中，类的定义放在.cpp文件中
////定义放在类的实现文件person.cpp中
//#include"person.h"
//void Person::showInfo()
//{
//	cout << _name << "-" << _sex<<"-" << _age << endl;
//}



//类的作用域
//类定义了一个新的作用域，类的所有成员都在类的作用域中。
//在类体外定义成员，需要使用：：作用域解析符指明成员属于哪个类域

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
////这里需要指定PrintPersonInfo是属于Person这个类域
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


// 类中既有成员变量，又有成员函数
class A1 {
public:
	void f1() {}
private:
	int _a;
};
// 类中仅有成员函数
class A2 {
public:
	void f2() {}
};
// 类中什么都没有---空类
class A3
{};