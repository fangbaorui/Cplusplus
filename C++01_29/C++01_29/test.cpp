#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
////namespace + 命名空间名称
//namespace N1   //N1为命名空间的名称
//{
//	//命名空间的内容，既可以定义变量也可以定义函数
//	int a = 0;
//	void fun1()
//	{
//		printf("N1:fun1()\n");
//	}
//
//	//命名空间可以嵌套
//	namespace N2
//	{
//		int a = 1;
//		void fun1()
//		{
//			printf("N1:N2:fun1()\n");
//		}
//	}
//}
////全局变量
//int a = 10;
//void fun1()
//{
//	printf("fun1()\n");
//}
////同一工程中允许存在多个相同名称的命名空间，编译器最后会合成同一个命名空间中
////分段定义
//namespace N1
//{
//	//int a;同一作用域中不允许重定义
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
//	//全局：a
//	printf("a: %d\n", a);  //10
//
//	//命名空间中成员的访问形式
//	//1.命名空间 :: 成员
//	printf("N1::a: %d\n", N1::a); //0
//	N1::fun2();
//	//2.using 命名空间 :: 成员
//	using N1::b;
//	printf("N1::b: %d\n", b);  //20
//	//3.展开命名空间：using namespace 命名空间
//	//命名空间下的所有成员全部都暴露在全局作用域中，会和全局域中的成员发生混淆
//	using namespace N1;
//	//printf("N1::a: %d\n", a);会和全局变量a产生冲突
//	printf("N1::c: %d\n", c);//30 ,全局变量没有c，不会产生冲突
//	fun2();
//}
//int main()
//{
//	test();
//	return 0;
//}



////使用cout标准输出(控制台)和cin标准输入(键盘)时，必须包含< iostream >头文件以及std标准命名空间
//#include<iostream>
//using namespace std;
//int main()
//{
//	//int a = 0;
//	//int b;
//	//cout << a << endl;
//	//cin >> b;
//	//cout << b << endl;
//	////如果没有using namespace std;可以写成
//	//std::cout << a << endl;
//	//std::cin >> b;
//	//cout << b;
//
//	int a, b, c;
//	//cin：支持连续输出，输入顺序从左向右
//	cin >> a >> b >> c;
//	//cout:支持连续输出，输出顺序从左向右
//	cout << a << b << c << "\n";
//	//输出空格，字符串
//	cout << a << " " << "abc";
//	return 0;
//}



////缺省参数
////缺省参数是声明或定义函数时为函数的参数指定一个默认值，在调用该函数时，
////如果没有指定实参则采用该默认值，否则使用指定的实参
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
////全缺省：所有参数都有默认值
//void fun3(int a = 1, int b = 2, int c = 3, int d = 4)
//{
//	cout << a << " " << b << " " << c << " " << d << endl;
//}
//
////半缺省：部分参数设置默认值
////设置参数默认值必须从右向左依次连续赋值，中间不能有间隔
//void fun4(int a, int b = 1, int c = 2)
//{
//	cout << a << " " << b << " " << c << endl;
//}
////以下三个都不符合规范
////void fun5(int a = 1, int b, int c = 2){}
////void fun6(int a, int b = 1, int c){}
////void fun7(int a = 1, int b = 2, int c){}
//
//
////声明和定义，只能有一个地方设置参数默认值，不能同时设置
////函数声明
//int fun6(int a = 10);
////函数定义
//int fun6(int  a)
//{
//	cout << a << endl;
//}
//
//void test()
//{
//	fun1(100); //100
//	fun2();    //10，没有传参时，使用参数的默认值
//	fun2(20);  //20，传参时，使用指定的实参
//
//	//接收参数的顺序是从左向右
//	fun3(10, 20); //10 20 3 4
//	fun3(10, 20, 30, 40); // 10 20 30 40
//}
//int main()
//{
//	test();
//	return 0;
//}


//函数重载
//函数重载:是函数的一种特殊情况，C++允许在同一作用域中声明几个功能类似的同名函数，这些同名函数的
//形参列表(参数个数 或 类型 或 顺序)必须不同，常用来处理实现功能类似数据类型不同的问题
//其他相同，只有函数返回值类型不同，不构成函数重载
//#include<iostream>
//using namespace std;
//参数类型不同
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
////参数顺序不同
//void fun(int b, char a)
//{
//	cout << "fun(int,char)" << endl;
//}
////参数个数不同
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

