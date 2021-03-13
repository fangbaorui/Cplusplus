#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

//对象在销毁时会自动调用析构函数，完成类的一些资源清理工作。
//析构函数是特殊的成员函数。
//其特征如下：
//1. 析构函数名是在类名前加上字符 ~。
//2. 无参数无返回值。
//3. 一个类有且只有一个析构函数。若未显式定义，系统会自动生成默认的析构函数。
//4. 对象生命周期结束时，C++编译系统系统自动调用析构函数。
//typedef int DataType;
//class Seqlist
//{
//public:
//	Seqlist(int capacity = 10)
//	{
//		_pData = (DataType*)malloc(capacity * sizeof(DataType));
//		assert(_pData);
//
//		_size = 0;
//		_capacity = capacity;
//	}
//	~SeqList()
//	{
//		if (_pData)
//		{
//			free(_pData); //释放堆上的空间
//			_pData = NULL; //将指针置为空
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//private:
//	int* _pData;
//	size_t _size;
//	size_t capacity;
//};



//编译器生成的默认析构函数，对会自定类型成员调用它的析构函数
//class String
//{
//public:
//	String(const char* str = "jack")
//	{
//		_str = (char*)malloc(strlen(str) + 1);
//		strcpy(_str, str);
//	}
//
//	~String()
//	{
//		cout << "!String()" << endl;
//		free(_str);
//	}
//
//private:
//	char* _str;
//};
//
//class Person
//{
//private:
//	String _name;
//	int _age;
//};
//
//int mian()
//{
//	Person p;
//	return 0;
//}




//4.2 特征
//拷贝构造函数也是特殊的成员函数，其特征如下：
//1. 拷贝构造函数是构造函数的一个重载形式。
//2. 拷贝构造函数的参数只有一个且必须使用引用传参，使用传值方式会引发无穷递归调用。
//class Data
//{
//public:
//	Data(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	Data(const Data& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
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
//	Data d1;
//	Data d2(d1);
//	return 0;
//}



// 若未显示定义，系统生成默认的拷贝构造函数。 默认的拷贝构造函数对象按内存存储按字节序完成拷
//贝，这种拷贝我们叫做浅拷贝，或者值拷贝
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	Date d2(d1);
//	return 0;
//}



//日期类实现
#include<iostream>
using namespace std;
class Date
{
public:
	Date(int y = 1, int m = 1, int d = 1)
	{
		//判断日期是否有效
		if (y <= 0 || m <= 0 || m > 12 || d <= 0 || d > getDay(y, m))
		{
			//日期无效
			_y = 1;
			_m = 1;
			_d = 1;
			cout << "日期无效，设为默认值:1-1-1" << endl;
		}
		_y = y;
		_m = m;
		_d = d;
	}

	int getDay(int y, int m)
	{
		static int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		int day = days[m];
		//如果是2月，且为闰年，修改天数
		if (m == 2 && (((y % 4 == 0) && (y % 100 != 0)) || y % 400 == 0))
			day += 1;
		return day;
	}


	//日期运算
	//左操作数+=右操作数：左操作数的内容发生变化，返回值：相加之和的值
	Date& operator+=(int day)
	{
		//判断日期是否为负数
		if (day < 0)
			return *this -= -day;

		
		//天数相加
		_d += day;

		//判断天数是否溢出
		while (_d > getDay(_y, _m))
		{
			//减去当月的天数
			_d -= getDay(_y, _m);

			//月份进位
			++_m;

			//判断月份是否溢出
			if (_m == 13)
			{
				//下月份的1月份
				//年份进位
				++_y;
				_m = 1;
			}
		}
		//返回相加之后的结果
		return *this;
	}

	//Date + int
	//加法：返回相加之后的结果，操作数不能改变
	Date operator+(int day)
	{
		Date copy(*this);
		//Date copr=*this;
		copy += day;
		return copy;
	}

	//++Date   前置++
	Date& operator++()
	{
		return *this += 1;
	}

	//Date++  后置++
	//int参数的作用：只是为了和前置++构成重载
	Date operator++(int)
	{
		Date copy(*this);
		*this += 1;
		//返回++之前的值
		return copy;
	}


	Date& operator-=(int day)
	{
		//判断日期是否为负数
		if (day < 0)
			return *this += -day;

		_d = day;
		while (_d <= 0)
		{
			//用上一个月的天数回补
			--_m;
			//判断月份是否溢出（向下）
			if (_m == 0)
			{
				//需要回退到上一年的12月份
				_y--;
				_m = 12;
			}
			_d += getDay(_y, _m);
		}
		return *this;
	}

	//Date - int
	Date operator-(int day)
	{
		Date copy(*this);
		//Date copr=*this;
		copy -= day;
		return copy;
	}

	//--Date   前置--
	Date& operator--()
	{
		return *this -= 1;
	}

	//Date--  后置--
	//int参数的作用：只是为了和前置--构成重载
	Date operator--(int)
	{
		Date copy(*this);
		*this -= 1;
		return copy;
	}

	//==
	bool operator==(const Date& d)
	{
		return _y == d._y
			&& _m == d._m
			&& _d == d._d;
	}


	//!=
	bool operator!=(const Date& d)
	{
		return !(* this == d);
	}

	//>
	bool operator>(const Date& d)
	{
		if (_y > d._y)
			return true;
		else if (_y == d._y)
		{
			if (_m > d._m)
				return true;
			else if (_m == d._m)
			{
				if (_d > d._d)
					return true;
			}
		}
		return false;
	}


	//>=
	bool operator>=(const Date& d)
	{
		return *this > d || *this == d;
	}

	//<
	bool operator<(const Date& d)
	{
		return !(*this >= d);
	}



	//<=
	bool operator<=(const Date& d)
	{
		return !(*this >d);
	}


	//日期相减：Date-Date
	//*this -d
	int operator-(const Date& d)
	{
		//计算比较小的日期经过多少从自加运算，可以和较大的日期相同
		//自加的次数就是相差的天数
		Date max = *this;
		Date min = d;
		int flag = 1;

		if (max < min)
		{
			max = d;
			min = *this;
			flag = -1;
		}
		int day = 0;
		while (min < max)
		{
			++min;
			++day;
		}
		return flag * day;
	}

private:
	int _y;
	int _m;
	int _d;
};


void test()
{
	Date d1(2021, 2, 5);
	Date d2(2021, 2, 5);
	Date d3(2021, 2, 5);
	Date d4(2021, 2, 5);

	d1 -= 1;
	d2 -= 30;
	d3 -= 90;
	d4 -= 360;

	d2 += -30;
	d3 += -90;
	d4 += -360;
}

//void test()
//{
//	Date d1(2021, 2, 4);
//	Date d2(2021, 2, 4);
//	Date d3(2021, 2, 4);
//	Date d4(2021, 2, 4);
//
//	d1.operator+=(1);
//
//	d2 += 30;
//	d3 += 90;
//	d4 += 360;
//
//	d3 = d4 + 90;
//
//	//前置++
//	d4 = ++d3;
//	//后置++
//	d4 = d3.operator++(10); //后置++
//	d4 = d3.operator++();  //前置++
//}

int main()
{
	test();
	return 0;
}