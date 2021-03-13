#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

//����������ʱ���Զ���������������������һЩ��Դ��������
//��������������ĳ�Ա������
//���������£�
//1. ������������������ǰ�����ַ� ~��
//2. �޲����޷���ֵ��
//3. һ��������ֻ��һ��������������δ��ʽ���壬ϵͳ���Զ�����Ĭ�ϵ�����������
//4. �����������ڽ���ʱ��C++����ϵͳϵͳ�Զ���������������
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
//			free(_pData); //�ͷŶ��ϵĿռ�
//			_pData = NULL; //��ָ����Ϊ��
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//private:
//	int* _pData;
//	size_t _size;
//	size_t capacity;
//};



//���������ɵ�Ĭ�������������Ի��Զ����ͳ�Ա����������������
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




//4.2 ����
//�������캯��Ҳ������ĳ�Ա���������������£�
//1. �������캯���ǹ��캯����һ��������ʽ��
//2. �������캯���Ĳ���ֻ��һ���ұ���ʹ�����ô��Σ�ʹ�ô�ֵ��ʽ����������ݹ���á�
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



// ��δ��ʾ���壬ϵͳ����Ĭ�ϵĿ������캯���� Ĭ�ϵĿ������캯�������ڴ�洢���ֽ�����ɿ�
//�������ֿ������ǽ���ǳ����������ֵ����
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



//������ʵ��
#include<iostream>
using namespace std;
class Date
{
public:
	Date(int y = 1, int m = 1, int d = 1)
	{
		//�ж������Ƿ���Ч
		if (y <= 0 || m <= 0 || m > 12 || d <= 0 || d > getDay(y, m))
		{
			//������Ч
			_y = 1;
			_m = 1;
			_d = 1;
			cout << "������Ч����ΪĬ��ֵ:1-1-1" << endl;
		}
		_y = y;
		_m = m;
		_d = d;
	}

	int getDay(int y, int m)
	{
		static int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		int day = days[m];
		//�����2�£���Ϊ���꣬�޸�����
		if (m == 2 && (((y % 4 == 0) && (y % 100 != 0)) || y % 400 == 0))
			day += 1;
		return day;
	}


	//��������
	//�������+=�Ҳ�������������������ݷ����仯������ֵ�����֮�͵�ֵ
	Date& operator+=(int day)
	{
		//�ж������Ƿ�Ϊ����
		if (day < 0)
			return *this -= -day;

		
		//�������
		_d += day;

		//�ж������Ƿ����
		while (_d > getDay(_y, _m))
		{
			//��ȥ���µ�����
			_d -= getDay(_y, _m);

			//�·ݽ�λ
			++_m;

			//�ж��·��Ƿ����
			if (_m == 13)
			{
				//���·ݵ�1�·�
				//��ݽ�λ
				++_y;
				_m = 1;
			}
		}
		//�������֮��Ľ��
		return *this;
	}

	//Date + int
	//�ӷ����������֮��Ľ�������������ܸı�
	Date operator+(int day)
	{
		Date copy(*this);
		//Date copr=*this;
		copy += day;
		return copy;
	}

	//++Date   ǰ��++
	Date& operator++()
	{
		return *this += 1;
	}

	//Date++  ����++
	//int���������ã�ֻ��Ϊ�˺�ǰ��++��������
	Date operator++(int)
	{
		Date copy(*this);
		*this += 1;
		//����++֮ǰ��ֵ
		return copy;
	}


	Date& operator-=(int day)
	{
		//�ж������Ƿ�Ϊ����
		if (day < 0)
			return *this += -day;

		_d = day;
		while (_d <= 0)
		{
			//����һ���µ������ز�
			--_m;
			//�ж��·��Ƿ���������£�
			if (_m == 0)
			{
				//��Ҫ���˵���һ���12�·�
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

	//--Date   ǰ��--
	Date& operator--()
	{
		return *this -= 1;
	}

	//Date--  ����--
	//int���������ã�ֻ��Ϊ�˺�ǰ��--��������
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


	//���������Date-Date
	//*this -d
	int operator-(const Date& d)
	{
		//����Ƚ�С�����ھ������ٴ��Լ����㣬���Ժͽϴ��������ͬ
		//�ԼӵĴ���������������
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
//	//ǰ��++
//	d4 = ++d3;
//	//����++
//	d4 = d3.operator++(10); //����++
//	d4 = d3.operator++();  //ǰ��++
//}

int main()
{
	test();
	return 0;
}