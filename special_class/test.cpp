#include<iostream>
#include<thread>
#include<mutex>
using namespace std;



//单例模式
//2.懒汉：第一次使用的时候创建对象
//加锁：保证串行操作
class singleton
{
public:
	//公有的方法获取对象
	static singleton* getSingleton()
	{
		//第一层检查：提高效率
		if (_sin == nullptr)
		{
			mtx.lock();
			//第二层检查：保证线程安全
			if (_sin == nullptr)
			{
				//第一次创建对象
				_sin = new singleton;
				cout << _sin << endl;
			}
			mtx.unlock();
		}
		return _sin;
	}
private:
	//构造函数私有
	singleton()
	{}

	//防拷贝
	singleton(const singleton&) = delete;

	//static指针成员
	static singleton* _sin;

	static mutex mtx;//互斥锁
};
singleton* singleton::_sin = nullptr;
mutex singleton::mtx;
void fun(int n)
{
	for (int i = 0; i < n; i++)
	{
		singleton::getSingleton();
	}
}

void test()
{
	//singleton* ptr = singleton::getSingleton();
	
	int n;
	cin >> n;
	thread t1(fun, n);
	thread t2(fun, n);
	t1.join();
	t2.join();
}






////单例模式
////1.饿汉
////a.对象只能被创建一次
////调用接口只是读的操作，多线程下也是安全的
//class singleton
//{
//public:
//	//公有的方法获取对象
//	static singleton* getSingleton()
//	{
//		//获取已存在对象的地址
//		return &_instance;
//	}
//
//private:
//	//构造函数私有
//	singleton()
//	{}
//
//	//定义一个类的static成员
//	static singleton _instance;
//
//	//防拷贝
//	singleton(const singleton&) = delete;
//};
//singleton singleton::_instance;
//void test()
//{
//	singleton* ptr = singleton::getSingleton();
//	//singleton copy(*ptr);
//}







////不能被继承的类
////把类定义为final类
//class A final
//{};
//
//class B :public A
//{};
//
////基类的构造函数定义为私有的
//class C
//{
//private:
//	C() {}
//};
//class D :public C
//{};
//void test()
//{
//	//D d;
//}




////设计一个类，只能在栈上创建对象
//class StackObj
//{
//public:
//	//禁止调用operator new
//	void* operator new(size_t n) = delete;
//};
//void test()
//{
//	//StackObj* ptr = new StackObj;
//	StackObj so;
//}





////设计一个类，只能在栈上创建对象
//class StackObj
//{
//public:
//	//公有的方法创建对象
//	static StackObj getObj()
//	{
//		return StackObj();
//	}
//	//构造函数私有
//private:
//	StackObj()
//	{}
//};
////全局的，在数据段
//StackObj so = StackObj::getObj();
//void test()
//{
//	//new StackObj;
//	//拷贝一般在栈上
//	StackObj so = StackObj::getObj();
//}



////设计一个类，只能在堆上创建对象
//class HeapObj
//{
//public:
//	//调用构造函数创建对象
//	static HeapObj* getObj()
//	{
//		return new HeapObj;
//	}
//	//禁止构造函数的调用：私有
//private:
//	HeapObj()
//	{}
//
//	//防拷贝
//	//只声明不实现
//	HeapObj(const HeapObj&);
//
//	//或者声明为delete函数
//	HeapObj(const HeapObj&) = delete;
//};
//void test()
//{
//	HeapObj* ptr = HeapObj::getObj();
//}

int main()
{
	test();
	return 0;
}