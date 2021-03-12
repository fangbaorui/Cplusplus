#define _CRT_SECURE_NO_WARNINGS

////this指针
//#include<iostream>
//using namespace std;
//class Date
//{
//public:
//	void Display()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//	void SetDate(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year; //年
//	int _month; //月
//	int _day; //日
//};
//
//int main()
//{
//	Date d1, d2;
//	d1.SetDate(2018, 5, 1);
//	d2.SetDate(2018, 7, 1);
//	d1.Display();
//	d2.Display();
//	return 0;
//}



//构造函数：不是开空间创建对象，而是初始化对象
//#include<iostream>
//using namespace std;
//class Date
//{
//public:
//	void SetDate(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Display()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1, d2;
//	d1.SetDate(2018, 5, 1);
//	d1.Display();
//
//	d2.SetDate(2018, 7, 1);
//	d2.Display();
//	return 0;
//}



//#include<iostream>
//using namespace std;
//class Date
//{
//public:
//	//1.无参构造函数
//	Date()
//	{}
//
//	//2.带参构造函数
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//void TestDate()
//{
//	Date d1; //调用无参构造函数
//	Date d2(2015,1,1); //调用带参的构造函数
//
//	//Date d3(); //属于函数声明
//}



////如果类中没有显示定义构造函数，则C++编译器会自动生成一个无参的默认构造函数，
////一旦用户显式定义，编译器将不再生成
//class Date
//{
//public:
//
//	/*
//	//如果显示定义构造函数，编译器将不会在生成
//	Date（int year, int month, int day)
//	{
//	   _year = year;
//	   _month = month;
//	   _day = day;
//     }
//	 */
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//void Test()
//{
//	//没有定义构造函数，对象也可以创建成功，因此此处调用的是编译器生成的默认构造函数
//	Date d;
//}


// 无参的构造函数和全缺省的构造函数都称为默认构造函数，并且默认构造函数只能有一个。注意：无参
//构造函数、全缺省构造函数、我们没写编译器默认生成的构造函数，都可以认为是默认成员函数。
//class Date
//{
//public:
//	////无参构造函数
//	//Date()
//	//{
//	//	_year = 1000;
//	//	_month = 1;
//	//	_day = 1;
//	//}
//
//	//全缺省
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//void Test()
//{
//	Date d1;
//}


//C++把类型分成内置类型(基本类型)和自定义类型。内置类型就是语法已经定义好的类型：如
//int / char...，自定义类型就是我们使用class / struct / union自己定义的类型，
//编译器生成默认的构造函数会对自定类型成员_t调用的它的默认成员函数
#include<iostream>
using namespace std;
class Time
{
public:
	Time()
	{
		cout << "Time()" << endl;
		_hour = 0;
		_minute = 0;
		_second = 0;
	}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
private:
	// 基本类型(内置类型)
	int _year;
	int _month;
	int _day;
	// 自定义类型
	Time _t;
};
int main()
{
	Date d;
	return 0;
}