#define _CRT_SECURE_NO_WARNINGS

////thisָ��
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
//	int _year; //��
//	int _month; //��
//	int _day; //��
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



//���캯�������ǿ��ռ䴴�����󣬶��ǳ�ʼ������
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
//	//1.�޲ι��캯��
//	Date()
//	{}
//
//	//2.���ι��캯��
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
//	Date d1; //�����޲ι��캯��
//	Date d2(2015,1,1); //���ô��εĹ��캯��
//
//	//Date d3(); //���ں�������
//}



////�������û����ʾ���幹�캯������C++���������Զ�����һ���޲ε�Ĭ�Ϲ��캯����
////һ���û���ʽ���壬����������������
//class Date
//{
//public:
//
//	/*
//	//�����ʾ���幹�캯����������������������
//	Date��int year, int month, int day)
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
//	//û�ж��幹�캯��������Ҳ���Դ����ɹ�����˴˴����õ��Ǳ��������ɵ�Ĭ�Ϲ��캯��
//	Date d;
//}


// �޲εĹ��캯����ȫȱʡ�Ĺ��캯������ΪĬ�Ϲ��캯��������Ĭ�Ϲ��캯��ֻ����һ����ע�⣺�޲�
//���캯����ȫȱʡ���캯��������ûд������Ĭ�����ɵĹ��캯������������Ϊ��Ĭ�ϳ�Ա������
//class Date
//{
//public:
//	////�޲ι��캯��
//	//Date()
//	//{
//	//	_year = 1000;
//	//	_month = 1;
//	//	_day = 1;
//	//}
//
//	//ȫȱʡ
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


//C++�����ͷֳ���������(��������)���Զ������͡��������;����﷨�Ѿ�����õ����ͣ���
//int / char...���Զ������;�������ʹ��class / struct / union�Լ���������ͣ�
//����������Ĭ�ϵĹ��캯������Զ����ͳ�Ա_t���õ�����Ĭ�ϳ�Ա����
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
	// ��������(��������)
	int _year;
	int _month;
	int _day;
	// �Զ�������
	Time _t;
};
int main()
{
	Date d;
	return 0;
}