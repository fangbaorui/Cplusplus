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
	//子类的初始化列表中不能直接初始化父类成员
	//父类的成员需要调用父类构造完成初始化
	//如果父类有默认构造，初始化列表中可以不用显示调用父类的构造函数，编译器会自动调用父类的默认构造
	//如果父类没有默认构造，必须显示调用父类的一个构造函数
	Student(int id,int age,int stuId)  
		:Person(id,age)    //成员的初始化顺序一定是先初始化父类，在初始化子类新定义的成员
		,_stuId(stuId)
	{
		cout << "Student(int,int,int)" << endl;
	}

	//拷贝构造的初始化列表中可以调用普通的父类构造函数
	//也可以调用拷贝构造
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
			//父类的赋值和子类的赋值运算符构成同名隐藏，需要加上父类作用域
			Person::operator=(stu);

			_stuId = stu._stuId;
		}
		cout << "Student& operator=(const Student& stu)" << endl;
		return *this;
	}

	//析构函数底层的函数名相同：destructor
	//子类析构和父类析构是同名隐藏
	//编译器在任何情况下都会自动调用父类的析构，不需要显示调用父类析构
	~Student()
	{
		//~Person();  //错误
		//Person::~Person();
		cout << "~Student()"<<endl;
	}
private:
	int _stuId;
};

void test()
{
	////子类的默认构造会自动调用父类的构造函数
	////Student stu;
	//Student stu(1, 2, 3);

	////子类的默认拷贝构造自动调用父类的拷贝构造
	////如果子类显示定义了拷贝构造，子类的拷贝构造会自动调用父类的默认构造
	//Student copy(stu);

	////赋值：子类的默认赋值运算符会自动调用父类的赋值运算符
	////子类定义的赋值运算符不会自动调用父类的赋值运算符，除非显示调用
	//stu = copy;

	//子类的默认析构或者显示定义的析构都会自动调用父类的默认析构
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
//	//同名隐藏，无论是成员变量还是成员函数，只要成员名称相同，就会构成同名隐藏
//	void fun()
//	{
//		cout << "B::fun()" << endl;
//	}
//
//	void printB()
//	{
//		cout << _a << endl;
//		//同名隐藏父类的成员变量，可以通过加上父类的作用域访问
//		cout << A::_a << endl;
//	}
//private:
//	int _a = 100;
//};
//
//void test()
//{
//	//继承的_a在子类中被隐藏了
//	B b;
//	b.printB();
//	//父类和子类中如果有名称相同的函数，就会构成同名隐藏
//	b.fun();
//	//如果需要访问父类的同名函数，需要加上父类作用域
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
//	string _name = "peter";  //string大小是28
//	int _age = 10;
//private:
//	int _id = 10;
//};
//
//class A
//{};
//
////class 定义的类，默认继承方式是private
////私有继承：父类中的所有成员，除过父类的private成员不可见，其他成员的访问权限在类外不可见
////class student:Person
////公有继承：除过父类的private成员不可见没其他成员的权限不会发生变化
//class student : public Person
//{
//	void printStu()
//	{
//		//protected成员在子类中可见，类外不可见
//		cout << _age << _name << endl;
//		//父类的私有成员被子类继承，但是子类不能访问父类的私有成员
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
//	//切片:子类对象，引用，指针赋给父类对应的对象，引用，指针
//	p = s;
//	Person& rs = s;   //只包含父类的
//	Person* ps = &s;   //只包含父类的
//
//	student rs2 = s;
//	student* ps2 = (student*) ps;   //包含子类的
//
//	//1.父类对象不能赋值给子类对象,强制类型转换也不行
//	//2.父类引用，指针不能直接赋值给子类的引用，指针，但是可以通过强制类型转换赋值
//	//不建议进行强制类型转换，因为可能会产生访问越界的问题
//	student& rp = (student&)rs;
//	student* pp = (student*)&p;
//}


int main()
{
	test();
	return 0;
}