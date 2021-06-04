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

	//weak_ptr���ܵ���ʹ��:��������ǽ��share_ptrѭ������
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
////1.֧�ָ�ֵ����
////2.ͨ�����ü�����֤��Դ����ȷ��Ψһ���ͷ�
////3.���߳��У�ͨ�������ý��д��в�������֤����������ȷ
////4.ÿһ������Դ�����Լ����������ü���
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
//		//�������ۼ�
//		//++(*_countPtr);
//		addCount();
//	}
//
//	SharedPtr operator=(const SharedPtr<T>& sp)
//	{
//		//if (this != &sp)
//		//�жϹ�����Ƿ�Ϊͬһ����Դ
//		if(_ptr!=sp._ptr)
//		{
//			//�������Լ�
//			//���������Ϊ0����ǰ���������һ���������Դ�Ķ���
//			//�������Դ���ͷ�
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
//			//�������ۼ�
//			//++(*_countPtr);
//			addCount();
//		}
//		return *this;
//	}
//
//	~SharedPtr()
//	{
//	    //�������Լ�
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
//	//ÿһ����Դ��һ����������
//	mutex* _mtx;
//};
//
//void fun(const SharedPtr<Data>& sp, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		//�޸����ü��������̰߳�ȫ��
//		SharedPtr<Data> copy(sp);
//		
//		//�������ݵĲ��������̰߳�ȫ��
//		copy->_y++;
//	}
//}
//void test()
//{
//	SharedPtr<Data> sp(new Data);
//	SharedPtr<Data> sp2(new Data);
//	int n = 10000;
//	//{t1,t2}��{t3,t4}���޸����ü���ʱ���ǲ��е�
//	//t1��t2���޸����ü���ʱ���Ǵ��е�
//	//t3��t4���޸����ü���ʱ���Ǵ��е�
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
//	//���ü���->ÿһ����Դ��Ӧһ��������
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
//	//sp,sp2,sp3�������ͬһ����Դ��һ��ȫ������
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
//	//������
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
//	//unique_ptr:��û�и�ֵ�Ϳ����ĳ����¿�������ʹ��
//
//	unique_ptr<Data> up(new Data);
//	//unique_ptr�Ŀ�������Ϊɾ������
//	//unique_ptr<Data> up2(up);
//	unique_ptr<Data> up3(new Data);
//	//unique_ptr��ֵ�����Ϊɾ������
//	//up3 = up;
//}




////auto_ptr����ֹʹ�ã�����Ȩת������
////auto_ptr:ģ��ʵ��
//template<class T>
//class AutoPtr
//{
//public:
//	//RALL
//	//���캯����ȡ��Դ�Ĺ���Ȩ
//	AutoPtr(T* ptr)
//		:_ptr(ptr)
//	{
//
//	}
//	//�������ͷ���Դ
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
//	//����Ȩת��
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
//			//����Ȩת��
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
//	//�����������ָ��
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



//����ָ�룺
//1.ʵ��RAII˼��
//2.ʵ��ָ�빦�ܣ�����*��->
//template<class T>
//class SmartPtr
//{
//public:
//	//���캯����ȡ��Դ
//	SmartPtr(T* ptr)
//		:_ptr(ptr)
//	{
//
//	}
//	//�������ͷ���Դ
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
//	//����������ʼ��,����д��,��Դ���ܶ���ͷ�
//	/*int* ptr = new int;
//	SmartPtr<int> sp(ptr);
//	SmartPtr<int> sp2(ptr);*/
//
//	//������ʼ��
//	SmartPtr<int> sp1(new int);
//	//SmartPtr<int> sp2 = (int*)malloc(sizeof(int));
//
//	SmartPtr<A> sp2(new A);
//
//	//����ָ�룬���������������Զ��ͷ��ڴ棬�������ڴ�й©������
//	*sp1 = 10;
//	sp2->_a = 100;
//	(*sp2)._a = 1000;
//
//	//��ָͨ�룬�ֶ��ͷ��ڴ�,�����ڴ�й©����
//	int* p = new int;
//	A* pa = new A;
//	*p = 1;
//	pa->_a = 5;
//	(*pa)._a = 55;
//	delete p;
//	delete pa;
//
//	return;//return֮�󣬲���ִ��������룬���������ͷ���Դ
//	cout << "test" << endl;
//}

int main()
{
	test();
	return 0;
}