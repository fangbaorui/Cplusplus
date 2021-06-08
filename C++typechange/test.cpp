#include<iostream>
#include<stdlib.h>
using namespace std;


class B
{
public:
	virtual void fun(){}
};
class C:public B
{};
void test()
{
	int a = 10;
	double f = 1.2;
	//��ʽ����ת��
	a = (int)f;//��û��(int),����ת��

	int* pa = &a;
	//ǿ������ת��
	a = (int)pa;

	int* p=(int*)malloc(4);

	//C++����ת����
	//1.static_cast:֧�����е���ʽ����ת��
	a = static_cast<int>(f);
	//���⣺֧�ָ���ָ��/���õ�����ָ��/���õ�ת��
	B* pb = new B;
	C* pc = (C*)pb;
	C* pc2 = static_cast<C*>(pb);
	//��֧������ǿ������ת��
	//a = static_cast<int>(pa);


	//2.reinterpret_cast:֧��ǿ������ת��
	a = reinterpret_cast<int>(pa);

	//3.const_cast:ȥ��������const����
	volatile const int c = 10;
	cout << "C addr:" << &c << endl;
	cout << "C:" << c << endl;
	int* pc3 = const_cast<int*>(&c);
	cout << "C addr:" <<pc3 << endl;
	*pc3 = 20;
	cout << "C:" << c << endl;
	//20,�����������⣬��Ҫ�Ӹ�volatile�ؼ���


	//4.dynamic_cast:ֻ���ڶ�̬�����µĸ�������/ָ������������ָ��ת��
	//dynamic_cast:�����Ƿ�ȫ��ֻ�а�ȫ���Ż�ת���ɹ�������ȫ������nullptr
	B* pb2 = new B;
	C* pc4 = dynamic_cast<C*>(pb2);//ת��ʧ��
	C* pc5 = static_cast<C*>(pb2);
	cout << pc4 << endl;
	cout << pc5 << endl;

	B* pb3 = new C;
	pc4 = dynamic_cast<C*>(pb3);
	pc5 = static_cast<C*>(pb3); //����ȫ
	cout << pc4 << endl;
	cout << pc5 << endl;
}

int main()
{
	test();
	return 0;
}