#include<iostream>
#include<thread>
#include<vector>
#include<atomic>
#include<mutex>
using namespace std;

int sum = 0;
//atomic<int> sum(0); //sum++是原子操作
mutex mtx;
void fun(int n)
{
	for (int i = 0; i < n; i++)
	{
		mtx.lock();
		sum++;
		mtx.unlock();
	}
}
void test()
{
	int n;
	cin >> n;
	thread t1(fun, n);
	thread t2(fun, n);
	t1.join();
	t2.join();
	cout << sum << endl;
}




//class threadManager
//{
//public:
//	threadManager(thread& t)
//		:_t(t)
//	{}
//
//	~threadManager()
//	{
//		if (_t.joinable())
//			_t.join();
//	}
//private:
//	thread& _t;
//};
//void test()
//{
//	thread t1([]{});
//	threadManager tm(t1);
//	//vector<int> v;
//	//v.at(3) = 10;
//	//return;
//	
//	return;
//}

//class A
//{
//public:
//	void fun1(int a, int b)
//	{
//		cout << "fun1(int,int)" << a << b << endl;
//	}
//};
//void fun(int& a)
//{
//	a *= 2;
//}
//void fun1(int* ptr)
//{
//	*ptr *= 2;
//}
//void fun2(int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		cout << i << " ";
//	}
//	cout << endl;
//}
//void test()
//{
//	thread t1(fun2, 10000);
//	t1.detach();//分离
//	cout << "test" << endl;
//}
//void test()
//{
//	A a;
//	//成员函数需要显示取地址,this指针需要显示传递
//	thread t1(&A::fun1, &a, 10, 20);
//	t1.join();
//
//	int a2 = 1;
//	thread t2(fun, a2);
//	t2.join();
//	cout << a2 << endl;//1,没有乘2
//
//	thread t3(fun1, &a2);
//	t3.join();
//	cout << a2 << endl;//2
//
//	//如果参数为引用类型，需要加ref转换
//	thread t4(fun, ref(a2));
//	t4.join();
//	cout << a2 << endl;//4
//}


//void fun(int a)
//{
//	cout << "fun(int a)" << endl;
//}
//struct Fun
//{
//	int operator()()
//	{
//		cout << "Fun operator()" << endl;
//	}
//};
//void test()
//{
//	//thread t;
//	//传函数指针
//	thread t(fun,10);
//	t.joinable();//判断线程是否结束，返回bool值
//	t.join(); //线程等待
//
//	//传仿函数对象
//	Fun f;
//	thread t2(f);
//	t2.join();
//
//	//传lambda表达式
//	thread t3([] {cout << "lambda" << endl; });
//	t3.join();
//	cout << "test()" << endl;
//}



//struct Sum
//{
//	int operator()(int a, int b)
//	{
//		return a + b;
//	}
//};
//void test()
//{
//	auto f = [](int a, int b) {return a + b; };
//	auto sum = f(10, 20);
//	//f是仿函数类，类似于对象s，底层调用operator()
//	Sum s;
//	s(10, 20);
//}



//int g = 10;
//auto f = [] {}; //块外捕捉列表为空
//typedef int(*ptr)(int); //函数指针，参数int，返回值int
//void test()
//{
//	auto f = [](int a) {return a; };
//	auto f2= [](int a) {return a; };
//	//不能进行赋值
//	//f=f2
//
//	//允许拷贝
//	auto f3(f);
//	//可以赋值给函数指针
//	ptr f4 = f;
//}


int main()
{
	test();
	return 0;
}

