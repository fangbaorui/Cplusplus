#define _CRT_SECURE_NO_WARNINGS


//���ò����¶���һ�����������Ǹ��Ѵ��ڵı���ȡ��һ������������������Ϊ���ñ������洢�ռ�
//���������õı�������ͬһ���ڴ档
//#include<stdio.h>
//int main()
//{
//	int a = 10;
//	int& ra = a; //������������
//	printf("a = %d\n", a);      //10
//	printf("ra = %d\n", ra);    //10
//	printf("a�ĵ�ַ��%p\n", a);    //ra��a�ĵ�ַ��ͬ
//	printf("ra�ĵ�ַ��%p\n", ra);  //ra��һ�����ã���a�ı�����ָ���a��ͬ��ʵ��
//	return 0;
//}


//struct A
//{
//	int a;
//	int b;
//};
//void test()
//{
//	A sa;
//	sa.a = 1;
//	sa.b = 2;
//
//	//���ã��������µĿռ�
//	A& rsa = sa;
//	//�����������µĿռ�
//	A copy = sa;
//
//	copy.a = 100;  //sa.a����ı�
//	rsa.a = 3;     //sa.a�ĳ���3
//}


//void test()
//{
//	//����ʵ������ʼ��
//	//int& ra;  û�г�ʼ��������ʱ����
//	int a = 10;
//	//�����ж������
//	int& ra = a;
//	int& ra1 = a;
//	int& ra2 = a;
//	ra = 5;      // a = ra = ra1 = ra2 = 5
//	ra1 = 10;    // a = ra = ra1 = ra2 = 10
//	ra2 = 20;    // a = ra = ra1 = ra2 = 20
//	a = 30;      // a = ra = ra1 = ra2 = 30
//
//	int b = 100;
//	//�����޸����õ�ָ�򣬶��ǰ�b�����ݸ�ֵ��ral��ָ���ʵ��
//	ra1 = b;
//}



//void test()
//{
//	//�����ã�����ָ���ʵ�岻���޸�
//    //const& ����
//	const int a = 10;
//	//int& ra = a;  �����������a�ǳ���
//	const int& ra = a;
//
//	//int& ra2 = 100;  �����������100�ǳ���
//	const int& ra2 = 100;
//
//	double d = 2.5;
//	int c = 10;
//	c = d;
//	//int& ra3 = d;  �����������,���Ͳ�ͬ
//	const int& ra3 = d;
//}



////������
//void Swap(int* a, int* b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//void Swap(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//void test()
//{
//	int a = 10;
//	int b = 20;
//	Swap(&a, &b);  //20, 10
//	Swap(a, b);  //10, 20
//}


//������ֵ
//�����������ʱ�����˺���������������ض���δ����ϵͳ�������ʹ�����÷���
//����Ѿ�����ϵͳ�ˣ������ʹ�ô�ֵ���ء�
//#include<iostream>
//using namespace std;
//int& add(int& a, int& b)
//{
//	//����������ֵ������ֵ������������Ҫ���ں�������������
//	//int c = a + b;
//	//return c;
//	return a += b;
//}
//void test()
//{
//	int a = 10;
//	int b = 20;
//	int& ra = add(a, b);
//	cout << a << b << endl;
//	cout << ra << endl;
//}



//��ֵ��Ϊ�������߷���ֵ���ͣ��ڴ��κͷ����ڼ䣬��������ֱ�Ӵ���ʵ�λ��߽���������ֱ�ӷ��أ�����
//����ʵ�λ��߷��ر�����һ����ʱ�Ŀ����������ֵ��Ϊ�������߷���ֵ���ͣ�Ч���Ƿǳ����µģ�������
//���������߷���ֵ���ͷǳ���ʱ��Ч�ʾ͸��͡�

//��ֵ��������Ч�ʱȽ�
//#include<time.h>
//#include<iostream>
//using namespace std;
//struct A
//{
//	int a[10000];
//};
//
//A globalA;
//
//void fun1(A a)
//{}
//
//void fun2(A& ra)
//{}
//
//void test()
//{
//	int n;
//	cout << "ѭ��������" << endl;
//	cin >> n;
//
//	size_t begin = clock();
//	for (int i = 0; i < n; i++)
//		fun1(globalA);
//	size_t end = clock();
//	cout << "��ֵtime��" << end - begin << endl;
//
//	begin = clock();
//	for (int i = 0; i < n; i++)
//		fun2(globalA);
//	end = clock();
//	cout << "������time��" << end - begin << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}


//ֵ��������Ϊ����ֵ���͵����ܱȽ�
//#include<time.h>
//#include<iostream>
//using namespace std;
//struct A
//{
//	int a[10000];
//};
//
//A globalA;
//
//A fun1()
//{
//	return globalA;
//}
//
//A& fun2()
//{
//	return globalA;
//}
//
//void test()
//{
//	int n;
//	cout << "ѭ��������" << endl;
//	cin >> n;
//
//	size_t begin = clock();
//	for (int i = 0; i < n; i++)
//		fun1();
//	size_t end = clock();
//	cout << "����ֵtime��" << end - begin << endl;
//
//	begin = clock();
//	for (int i = 0; i < n; i++)
//		fun2();
//	end = clock();
//	cout << "��������time��" << end - begin << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}



void test()
{
	int a = 10;
	int& ra = a;
	ra = 100;

	int al = 10;
	int* ral = &al;
	*ral = 100;

	//����++��ʵ�����ݵ�++
	ra++;
	//ָ��++����ַ��ƫ��
	ral++;
}


struct A
{
	int a[100];
};
void test()
{
	A a;
	A& ra = a;
	A* pa = &a;

	//sizeof ���ã�����ʵ��Ĵ�С
	int n = sizeof(ra);  //400
	//sizeof ָ�룺ָ��Ĵ�С
	int n2 = sizeof(pa);  //32λƽ̨��400
}