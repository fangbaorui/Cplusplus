//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//using namespace std;
//
////����ģ��
////T:ģ�����
//template <typename T>
//void Swap(T& a, T& b)
//{
//	T temp = a;
//	a = b;
//	b = temp;
//}
//
////�Զ�������
//struct A
//{
//	A(int a)
//		:_a(a)
//	{}
//	int _a = 1;
//};
//
//void test()
//{
//	int a = 1, b = 2;
//	char d = 'm', e = 'n';
//	double f = 1.2, g = 2.5;
//	A a1(10);
//	A a2(20);
//	Swap(a, b);
//	Swap(d, e);
//	Swap(f, g);
//
//	Swap(a1, a2);
//}
//int main()
//{
//	test();
//	return 0;
//}



//����ģ���ʵ����
//#include<iostream>
//using namespace std;
// template<class T>
// T Add(const T& a, const T& b)
// {
//	 return a + b;
// }
//
//void test()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.0, d2 = 20.0;
//	Add(a1, a2);
//	Add(d1, d2);
//
//	//1.�û��Լ���ǿ��ת��
//	Add(a1, (int)d1);
//
//	//2.ʹ����ʾʵ����
//	Add<int>(a1,d1);
//}
//int main()
//{
//	test();
//	return 0;
//}



////ģ�������ƥ��ԭ��
////һ����ģ�庯�����Ժ�һ��ͬ���ĺ���ģ��ͬʱ���ڣ�
////���Ҹú���ģ�廹���Ա�ʵ����Ϊ�����ģ�庯��
//
////���ڷ�ģ�庯����ͬ������ģ�壬���������������ͬ��
////�ڵ���ʱ�����ȵ��÷�ģ�庯��������Ӹ�ģ�������һ��ʵ����
////���ģ����Բ���һ�����и���ƥ��ĺ�������ô��ѡ��ģ��
//#include<iostream>
//using namespace std;
//
////ר�Ŵ���int�ļӷ�����
//int Add(int a, int b)
//{
//	return a + b;
//}
//
////ͨ�üӷ�����
//template<class T>
//T Add(T a, T b)
//{
//	return a + b;
//}
//void test()
//{
//	//���ģ�庯��ƥ�䣬����Ҫ����ģ��ʵ����
//	Add(1, 2);
//	//���ñ������ػ���Add�汾
//	Add<int>(1, 2);
//	//ģ�庯���������ɸ���ƥ��İ汾������������ʵ�����ɸ���ƥ���Add����
//	Add(1, 2.0);
//}
//int main()
//{
//	test();
//	return 0;
//}



#include<iostream>
using namespace std;

template <class T>
class seqList
{
public:
	seqList(int n)
		:_data(new T[n])
		, size(0)
		, capacity(n);
	{}

	T seqListAt(size_t pos);
private:
	T* _data;
	size_t size;
	size_t capacity;
};

//���ⶨ�庯������Ҫ�ӷ�������
template <class T>
seqList<T>::seqListAt(size_t pos)
{
	return _data[pos];
}



