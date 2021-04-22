#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<array>
using namespace std;

//��ģ���ػ���Ӧ�ó�����������ȡ
//ǰ�᣺����һ��ͨ�õ�ģ��
template <class T1,class T2>
struct D
{
	D(const T1& d1,const T2& d2)
		:_d1(d1)
		,_d2(d2)
	{
		cout << "D(T1,T2)" << endl;
	}
	T1 _d1;
	T2 _d2;
};

//�ػ�:ȫ�ػ������е����Ͷ��Ǿ�������
template <>
struct D<char, double>
{
	D(const char& d1, const double& d2)
		:_d1(d1)
		, _d2(d2)
	{
		cout << "D(char,double)" << endl;
	}
	char _d1;
	double _d2;
};

//ƫ�ػ�����1.ֻ�ػ���������
template <class T1>
struct D<T1,char>
{
	D(const T1& d1, const double& d2)
		:_d1(d1)
		, _d2(d2)
	{
		cout << "D(T1,char)" << endl;
	}
	T1 _d1;
	double _d2;
};
//ƫ�ػ���2.��ģ���������һ��������
template <class T1,class T2>
struct D<T1* ,T2*>
{
public:
	D(const T1& d1, const T2& d2)
		:_d1(d1)
		, _d2(d2)
	{
		cout << "D(T1*,T2*)" << endl;
	}
	T1 _d1;
	T2 _d2;
};


//void test()
//{
//	D<int, int> d(1,1); //ͨ��ģ���ʵ����
//	D<char,double> d2('a', 1.1); //ȫ�ػ�ģ���ʵ����
//	D<int, char> d3(1, 'a'); //ƫ�ػ�ģ��ʵ����
//	D<int*, int*> d4(1, 2); //ƫ�ػ�ģ��ʵ����
//
//}




//����ģ���ػ�
template <class T>
bool isEqual(T& a, T& b)
{
	return a == b;
}

bool isEqual(char* a, char* b)
{
	return 0 == strcmp(a, b);
}

//template<>
//bool isEqual<char*>(char*& a, char*& b)
//{
//	return 0 == strcmp(a, b);
//}
//void test()
//{
//	int a = 1;
//	int b = 1;
//	int* pa = &a;
//	int* pa2 = &a;
//	bool ret = isEqual(a, b);
//	ret = isEqual(pa, pa2);
//
//	char* ptr1 = "1234";
//	char* ptr2 = "1234";
//	ret = isEqual(ptr1, ptr2);
//
//	char ptr3[] = "1234";
//	char ptr4[] = "1234";
//	ret = isEqual(ptr3, ptr4);
//}


//void test()
//{
//	array<int, 20> a;
//}

int main()
{
	test();
	return 0;
}