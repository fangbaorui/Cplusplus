#define _CRT_SECURE_NO_WARNINGS


//引用不是新定义一个变量，而是给已存在的变量取了一个别名，编译器不会为引用变量开存储空间
//它和它引用的变量共用同一块内存。
//#include<stdio.h>
//int main()
//{
//	int a = 10;
//	int& ra = a; //定义引用类型
//	printf("a = %d\n", a);      //10
//	printf("ra = %d\n", ra);    //10
//	printf("a的地址：%p\n", a);    //ra和a的地址相同
//	printf("ra的地址：%p\n", ra);  //ra是一个引用，是a的别名，指向和a相同的实体
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
//	//引用：不分配新的空间
//	A& rsa = sa;
//	//拷贝：分配新的空间
//	A copy = sa;
//
//	copy.a = 100;  //sa.a不会改变
//	rsa.a = 3;     //sa.a改成了3
//}


//void test()
//{
//	//引用实体必须初始化
//	//int& ra;  没有初始化，编译时出错
//	int a = 10;
//	//变量有多个引用
//	int& ra = a;
//	int& ra1 = a;
//	int& ra2 = a;
//	ra = 5;      // a = ra = ra1 = ra2 = 5
//	ra1 = 10;    // a = ra = ra1 = ra2 = 10
//	ra2 = 20;    // a = ra = ra1 = ra2 = 20
//	a = 30;      // a = ra = ra1 = ra2 = 30
//
//	int b = 100;
//	//不是修改引用的指向，而是把b的内容赋值给ral所指向的实体
//	ra1 = b;
//}



//void test()
//{
//	//常引用：引用指向的实体不能修改
//    //const& 类型
//	const int a = 10;
//	//int& ra = a;  该语句编译出错，a是常量
//	const int& ra = a;
//
//	//int& ra2 = 100;  该语句编译出错，100是常量
//	const int& ra2 = 100;
//
//	double d = 2.5;
//	int c = 10;
//	c = d;
//	//int& ra3 = d;  该语句编译出错,类型不同
//	const int& ra3 = d;
//}



////做参数
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


//做返回值
//如果函数返回时，出了函数作用域，如果返回对象还未还给系统，则可以使用引用返回
//如果已经还给系统了，则必须使用传值返回。
//#include<iostream>
//using namespace std;
//int& add(int& a, int& b)
//{
//	//引用做返回值，返回值的生命周期需要大于函数的生命周期
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



//以值作为参数或者返回值类型，在传参和返回期间，函数不会直接传递实参或者将变量本身直接返回，而是
//传递实参或者返回变量的一份临时的拷贝，因此用值作为参数或者返回值类型，效率是非常低下的，尤其是
//当参数或者返回值类型非常大时，效率就更低。

//传值、传引用效率比较
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
//	cout << "循环次数：" << endl;
//	cin >> n;
//
//	size_t begin = clock();
//	for (int i = 0; i < n; i++)
//		fun1(globalA);
//	size_t end = clock();
//	cout << "传值time：" << end - begin << endl;
//
//	begin = clock();
//	for (int i = 0; i < n; i++)
//		fun2(globalA);
//	end = clock();
//	cout << "传引用time：" << end - begin << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}


//值和引用作为返回值类型的性能比较
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
//	cout << "循环次数：" << endl;
//	cin >> n;
//
//	size_t begin = clock();
//	for (int i = 0; i < n; i++)
//		fun1();
//	size_t end = clock();
//	cout << "返回值time：" << end - begin << endl;
//
//	begin = clock();
//	for (int i = 0; i < n; i++)
//		fun2();
//	end = clock();
//	cout << "返回引用time：" << end - begin << endl;
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

	//引用++，实体内容的++
	ra++;
	//指针++，地址的偏移
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

	//sizeof 引用：引用实体的大小
	int n = sizeof(ra);  //400
	//sizeof 指针：指针的大小
	int n2 = sizeof(pa);  //32位平台下400
}