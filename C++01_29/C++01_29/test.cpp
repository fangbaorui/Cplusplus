#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
////namespace + �����ռ�����
//namespace N1   //N1Ϊ�����ռ������
//{
//	//�����ռ�����ݣ��ȿ��Զ������Ҳ���Զ��庯��
//	int a = 0;
//	void fun1()
//	{
//		printf("N1:fun1()\n");
//	}
//
//	//�����ռ����Ƕ��
//	namespace N2
//	{
//		int a = 1;
//		void fun1()
//		{
//			printf("N1:N2:fun1()\n");
//		}
//	}
//}
////ȫ�ֱ���
//int a = 10;
//void fun1()
//{
//	printf("fun1()\n");
//}
////ͬһ������������ڶ����ͬ���Ƶ������ռ䣬����������ϳ�ͬһ�������ռ���
////�ֶζ���
//namespace N1
//{
//	//int a;ͬһ�������в������ض���
//	int b = 20;
//	int c = 30;
//	void fun2()
//	{
//		printf("N1:fun2()\n");
//	}
//}
//
//void test()
//{
//	//ȫ�֣�a
//	printf("a: %d\n", a);  //10
//
//	//�����ռ��г�Ա�ķ�����ʽ
//	//1.�����ռ� :: ��Ա
//	printf("N1::a: %d\n", N1::a); //0
//	N1::fun2();
//	//2.using �����ռ� :: ��Ա
//	using N1::b;
//	printf("N1::b: %d\n", b);  //20
//	//3.չ�������ռ䣺using namespace �����ռ�
//	//�����ռ��µ����г�Աȫ������¶��ȫ���������У����ȫ�����еĳ�Ա��������
//	using namespace N1;
//	//printf("N1::a: %d\n", a);���ȫ�ֱ���a������ͻ
//	printf("N1::c: %d\n", c);//30 ,ȫ�ֱ���û��c�����������ͻ
//	fun2();
//}
//int main()
//{
//	test();
//	return 0;
//}



////ʹ��cout��׼���(����̨)��cin��׼����(����)ʱ���������< iostream >ͷ�ļ��Լ�std��׼�����ռ�
//#include<iostream>
//using namespace std;
//int main()
//{
//	//int a = 0;
//	//int b;
//	//cout << a << endl;
//	//cin >> b;
//	//cout << b << endl;
//	////���û��using namespace std;����д��
//	//std::cout << a << endl;
//	//std::cin >> b;
//	//cout << b;
//
//	int a, b, c;
//	//cin��֧���������������˳���������
//	cin >> a >> b >> c;
//	//cout:֧��������������˳���������
//	cout << a << b << c << "\n";
//	//����ո��ַ���
//	cout << a << " " << "abc";
//	return 0;
//}



////ȱʡ����
////ȱʡ�������������庯��ʱΪ�����Ĳ���ָ��һ��Ĭ��ֵ���ڵ��øú���ʱ��
////���û��ָ��ʵ������ø�Ĭ��ֵ������ʹ��ָ����ʵ��
//#include<iostream>
//using namespace std;
//void fun1(int a)
//{
//	cout << a << endl;
//}
//void fun2(int a = 10)
//{
//	cout << a << endl;
//}
//
////ȫȱʡ�����в�������Ĭ��ֵ
//void fun3(int a = 1, int b = 2, int c = 3, int d = 4)
//{
//	cout << a << " " << b << " " << c << " " << d << endl;
//}
//
////��ȱʡ�����ֲ�������Ĭ��ֵ
////���ò���Ĭ��ֵ���������������������ֵ���м䲻���м��
//void fun4(int a, int b = 1, int c = 2)
//{
//	cout << a << " " << b << " " << c << endl;
//}
////���������������Ϲ淶
////void fun5(int a = 1, int b, int c = 2){}
////void fun6(int a, int b = 1, int c){}
////void fun7(int a = 1, int b = 2, int c){}
//
//
////�����Ͷ��壬ֻ����һ���ط����ò���Ĭ��ֵ������ͬʱ����
////��������
//int fun6(int a = 10);
////��������
//int fun6(int  a)
//{
//	cout << a << endl;
//}
//
//void test()
//{
//	fun1(100); //100
//	fun2();    //10��û�д���ʱ��ʹ�ò�����Ĭ��ֵ
//	fun2(20);  //20������ʱ��ʹ��ָ����ʵ��
//
//	//���ղ�����˳���Ǵ�������
//	fun3(10, 20); //10 20 3 4
//	fun3(10, 20, 30, 40); // 10 20 30 40
//}
//int main()
//{
//	test();
//	return 0;
//}


//��������
//��������:�Ǻ�����һ�����������C++������ͬһ�����������������������Ƶ�ͬ����������Щͬ��������
//�β��б�(�������� �� ���� �� ˳��)���벻ͬ������������ʵ�ֹ��������������Ͳ�ͬ������
//������ͬ��ֻ�к�������ֵ���Ͳ�ͬ�������ɺ�������
//#include<iostream>
//using namespace std;
//�������Ͳ�ͬ
//int Add(int a, int b)
//{
//	return a + b;
//}
//double Add(double a, double b)
//{
//	return a + b;
//}
//int main()
//{
//	Add(10, 20);
//	Add(10.0, 20.0);
//	return 0;
//}


//#include<iostream>
//using namespace std;
//void fun(char a,int b)
//{
//	cout << "fun(char,int)" << endl;
//}
////����˳��ͬ
//void fun(int b, char a)
//{
//	cout << "fun(int,char)" << endl;
//}
////����������ͬ
//void fun(char a, int b, char c)
//{
//	cout << "fun(char,int char)" << endl;
//}
//int main()
//{
//	int a = 1;
//	char b = 'a';
//	fun(a, b);//fun(int,char)
//	fun(b, a);//fun(char,int)
//	fun(b, a, b);//fun(char,int char)
//}

