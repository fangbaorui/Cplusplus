#include<iostream>
#include<memory>
#include<thread>
#include<mutex>
using namespace std;


struct Data
{
	int _y = 1;
	int _m = 2;
	int _d = 3;

	~Data()
	{
		cout << "~Data" << endl;
	}
};
struct ListNode
{
	/*shared_ptr<ListNode> _next;
	shared_ptr<ListNode> _prev;*/
	weak_ptr<ListNode> _next;
	weak_ptr<ListNode> _prev;
	int _data;

	~ListNode()
	{
		cout << "~ListNode" << endl;
	}
};

void test()
{
	shared_ptr<ListNode> n1(new ListNode);
	shared_ptr<ListNode> n2(new ListNode);

	cout << n1.use_count() << endl;
	cout << n2.use_count() << endl;

	n1->_next = n2;
	n2->_prev = n1;
	cout << n1.use_count() << endl;
	cout << n2.use_count() << endl;

	//weak_ptr不能单独使用:最大作用是解决share_ptr循环引用
	//weak_ptr<Data> wp(new Data);
	weak_ptr<Data> wp;
	wp = n1;
}


//struct Data
//{
//	int _y = 1;
//	int _m = 2;
//	int _d = 3;
//
//	~Data()
//	{
//		cout << "~Data" << endl;
//	}
//};
////1.支持赋值拷贝
////2.通过引用计数保证资源被正确且唯一的释放
////3.多线程中，通过对引用进行串行操作，保证计数更新正确
////4.每一个恶资源都有自己独立的引用计数
//template<class T>
//class SharedPtr
//{
//public:
//	SharedPtr(T* ptr)
//		:_ptr(ptr)
//		,_countPtr(new size_t(1))
//		,_mtx(new mutex)
//	{}
//
//	SharedPtr(const SharedPtr<T>& sp)
//		:_ptr(sp._ptr)
//		,_countPtr(sp._countPtr)
//		,_mtx(sp._mtx)
//	{
//
//		//计数器累加
//		//++(*_countPtr);
//		addCount();
//	}
//
//	SharedPtr operator=(const SharedPtr<T>& sp)
//	{
//		//if (this != &sp)
//		//判断管理的是否为同一份资源
//		if(_ptr!=sp._ptr)
//		{
//			//计数器自减
//			//如果计数器为0，当前对象是最后一个管理此资源的对象
//			//负责对资源的释放
//			//if (--(*_countPtr) == 0)
//			if(subCount()==0)
//			{
//				delete _ptr;
//				delete _countPtr;
//				delete _mtx;
//			}
//			_ptr = sp._ptr;
//			_countPtr = sp._countPtr;
//
//			//计数器累加
//			//++(*_countPtr);
//			addCount();
//		}
//		return *this;
//	}
//
//	~SharedPtr()
//	{
//	    //计数器自减
//		//if (--(*_countPtr) == 0)
//		if(subCount()==0)
//		{
//			delete _ptr;
//			delete _countPtr;
//			delete _mtx;
//			_ptr = nullptr;
//			_countPtr = nullptr;
//			_mtx = nullptr;
//		}
//	}
//
//	T& operator*()
//	{
//		return *_ptr;
//	}
//
//	T* operator->()
//	{
//		return _ptr;
//	}
//
//	size_t getCount()
//	{
//		return *_countPtr;
//	}
//
//	size_t addCount()
//	{
//		_mtx->lock();
//		++_countPtr;
//		_mtx->unlock();
//		return *_countPtr;
//	}
//
//	size_t subCount()
//	{
//		_mtx->lock();
//		--_countPtr;
//		_mtx->unlock();
//		return *_countPtr;
//	}
//private:
//	T* _ptr;
//	size_t* _countPtr;
//	//每一份资源有一个独立的锁
//	mutex* _mtx;
//};
//
//void fun(const SharedPtr<Data>& sp, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		//修改引用计数，是线程安全的
//		SharedPtr<Data> copy(sp);
//		
//		//对于数据的操作不是线程安全的
//		copy->_y++;
//	}
//}
//void test()
//{
//	SharedPtr<Data> sp(new Data);
//	SharedPtr<Data> sp2(new Data);
//	int n = 10000;
//	//{t1,t2}和{t3,t4}在修改引用计数时，是并行的
//	//t1和t2在修改引用计数时，是串行的
//	//t3和t4哎修改引用计数时，是串行的
//	thread t1(fun, ref(sp), n);
//	thread t2(fun, ref(sp), n);
//	thread t3(fun, ref(sp2), n);
//	thread t4(fun, ref(sp2), n);
//	t1.join();
//	t2.join();
//	t3.join();
//	t4.join();
//	cout << sp.getCount() << endl;
//	cout << sp2.getCount() << endl;
//}

//void test()
//{
//	SharedPtr<Data> sp(new Data);
//	SharedPtr<Data> sp2(new Data);
//	SharedPtr<Data> copy(sp);
//	sp2 = sp;
//}






//struct Data
//{
//	int _y = 1;
//	int _m = 2;
//	int _d = 3;
//
//	~Data()
//	{
//		cout << "~Data" << endl;
//	}
//};
//void test()
//{
//	//引用计数->每一份资源对应一个计数器
//	shared_ptr<Data> sp(new Data);
//	cout << sp.use_count() << endl;//1
//	shared_ptr<Data> sp2(sp);
//	cout << sp.use_count() << endl;//2
//	cout << sp2.use_count() << endl;//2
//	shared_ptr<Data> sp3(new Data);
//	cout << sp.use_count() << endl;//2
//	cout << sp2.use_count() << endl;//2
//	cout << sp3.use_count() << endl;//1
//	sp3 = sp;
//	sp3 = sp2;
//
//	//sp,sp2,sp3管理的是同一份资源，一改全都改了
//	sp->_y = 2020;
//	sp2->_m = 10;
//	sp3->_d = 30;
//	cout << sp.use_count() << endl;//3
//	cout << sp2.use_count() << endl;//3
//	cout << sp3.use_count() << endl;//3
//}




//template<class T>
//class UniquePtr
//{
//public:
//	UniquePtr(T* ptr)
//		:_ptr(ptr);
//	{}
//
//	//防拷贝
//	UniquePtr(const UniquePtr<T>& up) = delete;
//	UniquePtr<T> operator=(const UniquePtr<T>& up) = delete;
//
//	~UniquePtr()
//	{
//		if (_ptr)
//		{
//			delete _ptr;
//			_ptr = nullptr;
//		}
//	}
//private:
//	T* _ptr;
//};
//struct Data
//{
//	int _y = 1;
//	int _m = 2;
//	int _d = 3;
//
//	~Data()
//	{
//		cout << "~Data" << endl;
//	}
//};
//void test()
//{
//	//unique_ptr:在没有赋值和拷贝的场景下可以正常使用
//
//	unique_ptr<Data> up(new Data);
//	//unique_ptr的拷贝构造为删除函数
//	//unique_ptr<Data> up2(up);
//	unique_ptr<Data> up3(new Data);
//	//unique_ptr赋值运算符为删除函数
//	//up3 = up;
//}




////auto_ptr；禁止使用，管理权转移问题
////auto_ptr:模拟实现
//template<class T>
//class AutoPtr
//{
//public:
//	//RALL
//	//构造函数获取资源的管理权
//	AutoPtr(T* ptr)
//		:_ptr(ptr)
//	{
//
//	}
//	//析构中释放资源
//	~AutoPtr()
//	{
//		if (_ptr)
//			delete _ptr;
//	}
//	T* operator->()
//	{
//		return _ptr;
//	}
//
//	T& operator*()
//	{
//		return _ptr;
//	}
//
//	//管理权转移
//	AutoPtr(AutoPtr<T>& ap)
//		:_ptr(ptr)
//	{
//		ap._ptr = nullptr;
//	}
//
//	AutoPtr<T>& operator=(AutoPtr<T>& ap)
//	{
//		if (this != &ap)
//		{
//			if(_ptr)
//				delete _ptr;
//			//管理权转移
//			_ptr = ap._ptr;
//			ap._ptr = nullptr;
//		}
//		return *this;
//	}
//private:
//	T* _ptr;
//};
//
//void test()
//{
//	//库里面的智能指针
//	auto_ptr<int> ap(new int);
//	auto_ptr<int> ap2(new int(3));
//	*ap = 10;
//	*ap2 = 100;
//
//	auto_ptr<int> ap3 = ap;
//	*ap = 100;
//
//	int* pa = new int;
//	int* pa2 = pa;
//}



//智能指针：
//1.实现RAII思想
//2.实现指针功能：重载*，->
//template<class T>
//class SmartPtr
//{
//public:
//	//构造函数获取资源
//	SmartPtr(T* ptr)
//		:_ptr(ptr)
//	{
//
//	}
//	//析构中释放资源
//	~SmartPtr()
//	{
//		if (_ptr)
//			delete _ptr;
//	}
//	T* operator->()
//	{
//		return _ptr;
//	}
//
//	T& operator*()
//	{
//		return _ptr;
//	}
//private:
//	T* _ptr;
//};
//class A
//{
//public:
////private:
//	int _a = 10;
//};
//void test()
//{
//	//不叫立即初始化,错误写法,资源可能多次释放
//	/*int* ptr = new int;
//	SmartPtr<int> sp(ptr);
//	SmartPtr<int> sp2(ptr);*/
//
//	//立即初始化
//	SmartPtr<int> sp1(new int);
//	//SmartPtr<int> sp2 = (int*)malloc(sizeof(int));
//
//	SmartPtr<A> sp2(new A);
//
//	//智能指针，编译器调用析构自动释放内存，不存在内存泄漏的问题
//	*sp1 = 10;
//	sp2->_a = 100;
//	(*sp2)._a = 1000;
//
//	//普通指针，手动释放内存,存在内存泄漏问题
//	int* p = new int;
//	A* pa = new A;
//	*p = 1;
//	pa->_a = 5;
//	(*pa)._a = 55;
//	delete p;
//	delete pa;
//
//	return;//return之后，不会执行下面代码，但会析构释放资源
//	cout << "test" << endl;
//}

int main()
{
	test();
	return 0;
}