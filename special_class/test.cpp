#include<iostream>
#include<thread>
#include<mutex>
using namespace std;



//����ģʽ
//2.��������һ��ʹ�õ�ʱ�򴴽�����
//��������֤���в���
class singleton
{
public:
	//���еķ�����ȡ����
	static singleton* getSingleton()
	{
		//��һ���飺���Ч��
		if (_sin == nullptr)
		{
			mtx.lock();
			//�ڶ����飺��֤�̰߳�ȫ
			if (_sin == nullptr)
			{
				//��һ�δ�������
				_sin = new singleton;
				cout << _sin << endl;
			}
			mtx.unlock();
		}
		return _sin;
	}
private:
	//���캯��˽��
	singleton()
	{}

	//������
	singleton(const singleton&) = delete;

	//staticָ���Ա
	static singleton* _sin;

	static mutex mtx;//������
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






////����ģʽ
////1.����
////a.����ֻ�ܱ�����һ��
////���ýӿ�ֻ�Ƕ��Ĳ��������߳���Ҳ�ǰ�ȫ��
//class singleton
//{
//public:
//	//���еķ�����ȡ����
//	static singleton* getSingleton()
//	{
//		//��ȡ�Ѵ��ڶ���ĵ�ַ
//		return &_instance;
//	}
//
//private:
//	//���캯��˽��
//	singleton()
//	{}
//
//	//����һ�����static��Ա
//	static singleton _instance;
//
//	//������
//	singleton(const singleton&) = delete;
//};
//singleton singleton::_instance;
//void test()
//{
//	singleton* ptr = singleton::getSingleton();
//	//singleton copy(*ptr);
//}







////���ܱ��̳е���
////���ඨ��Ϊfinal��
//class A final
//{};
//
//class B :public A
//{};
//
////����Ĺ��캯������Ϊ˽�е�
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




////���һ���ֻ࣬����ջ�ϴ�������
//class StackObj
//{
//public:
//	//��ֹ����operator new
//	void* operator new(size_t n) = delete;
//};
//void test()
//{
//	//StackObj* ptr = new StackObj;
//	StackObj so;
//}





////���һ���ֻ࣬����ջ�ϴ�������
//class StackObj
//{
//public:
//	//���еķ�����������
//	static StackObj getObj()
//	{
//		return StackObj();
//	}
//	//���캯��˽��
//private:
//	StackObj()
//	{}
//};
////ȫ�ֵģ������ݶ�
//StackObj so = StackObj::getObj();
//void test()
//{
//	//new StackObj;
//	//����һ����ջ��
//	StackObj so = StackObj::getObj();
//}



////���һ���ֻ࣬���ڶ��ϴ�������
//class HeapObj
//{
//public:
//	//���ù��캯����������
//	static HeapObj* getObj()
//	{
//		return new HeapObj;
//	}
//	//��ֹ���캯���ĵ��ã�˽��
//private:
//	HeapObj()
//	{}
//
//	//������
//	//ֻ������ʵ��
//	HeapObj(const HeapObj&);
//
//	//��������Ϊdelete����
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