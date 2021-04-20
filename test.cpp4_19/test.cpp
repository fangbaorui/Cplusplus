#define _CRT_SECURE_NO_WARNINGS
#include<list>
#include<stack>
#include<iostream>
#include<vector>
#include<queue>
#include<deque>
#include<functional>
using namespace std;


//�º����ࣺ���ء������������
template<class T>
struct Greater
{
	bool operator()(const T& a, const T& b)
	{
		return a > b;
	}
};
//void test()
//{
//	Greater<int> g;
//	bool ret = g.operator()(10, 20);
//	ret = g(10, 20); //��д��ʽg.operator()(10, 20)
//}

template<class T>
struct Less
{
	bool operator()(const T& a, const T& b)
	{
		return a < b;
	}
};

////���ȼ�����Ĭ����vectorʵ�֣�Ҳ֧��deque����֧��list
//void test()
//{
//	//���ʵ��
//	//priority_queue<int, vector<int>,Less<int>> pq;
//	//С��ʵ��
//	priority_queue<int, vector<int>, Greater<int>> pq;
//	//priority_queue<int, deque<int>> pq;
//	//��֧��list��list��֧���������
//	pq.push(100);
//	pq.push(1);
//	pq.push(125);
//	pq.push(10);
//	pq.push(0);
//	while (!pq.empty())
//	{
//		cout << pq.top() << " ";
//		pq.pop();
//	}
//	cout << endl;
//}

//˫�˶���ʵ��
//ʵ�ִ�ѽṹ
template <class T,class Container,class Compare>
class PriorityQueue
{
public:
	//�ѣ����µ���
	void shiftDown()
	{
		int parent = 0;
		int child = 2 * parent + 1;
		while (child < arr.size())
		{
			if (child + 1 < arr.size() && cmp(arr[child],arr[child + 1]))
			//if (child + 1 < arr.size() && arr[child] < arr[child + 1])
				child++;

			if (cmp(arr[parent],arr[child]))
			//if (arr[parent] < arr[child])
			{
				swap(arr[parent], arr[child]);

				//����λ��
				parent = child;
				child = 2 * parent + 1;
			}
			else
				break;
		}
	}

	//���ϵ���
	void shiftUp(int child)
	{
		int parent = (child - 1) / 2;
		while (child > 0)
		{
			if (cmp(arr[parent],arr[child]))
			//if (arr[parent] < arr[child])
			{
				swap(arr[parent], arr[child]);

				//����λ��
				child = parent;
				parent = (child - 1) / 2;
			}
			else
				break;
		}
	}

	void push(const T& val)
	{
		//β��
		arr.push_back(val);
		//���ϵ���
		shiftUp(arr.size() - 1);
	}

	void pop()
	{
		//����
		swap(arr[0], arr[arr.size() - 1]);
		//βɾ
		arr.pop_back();
		//���µ���
		shiftDown();
	}

	T& top()
	{
		return arr.front();
	}

	size_t size() const
	{
		return arr.size();
	}
	bool empty() const
	{
		return arr.empty();
	}
private:
	//vector<T> arr;
	Container arr;
	Compare cmp;
};

void test()
{
	//PriorityQueue<int, vector<int>,Greater<int>> pq;
	PriorityQueue<int, vector<int>, Less<int>> pq;
	pq.push(100);
	pq.push(1);
	pq.push(125);
	pq.push(10);
	pq.push(0);
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}






////���ȼ�����Ĭ����vectorʵ�֣�Ҳ֧��deque����֧��list
//void test()
//{
//	//Ĭ�ϴ��ʵ��
//	//priority_queue<int, vector<int>> pq;
//	priority_queue<int, deque<int>> pq;
//	//��֧��list��list��֧���������
//	pq.push(100);
//	pq.push(1);
//	pq.push(125);
//	pq.push(10);
//	pq.push(0);
//	while (!pq.empty())
//	{
//		cout << pq.top() << " ";
//		pq.pop();
//	}
//	cout << endl;
//
//}



////Ĭ��ʹ��˫�˶���ʵ�ֶ���
////size,empty,back,front,push_back,pop_front
//template<class T,class Container=deque<T>>
//class Queue
//{
//public:
//	void push(const T& val)
//	{
//		_c.push_back(val);
//	}
//	void pop()
//	{
//		_c.pop_front();
//	}
//	T& front()
//	{
//		return _c.front();
//	}
//	T& back()
//	{
//		return _c.back();
//	}
//	size_t size() const
//	{
//		return _c.size();
//	}
//	bool empty() const
//	{
//		return _c.empty();
//	}
//private:
//	Container _c;
//};
//
//void test()
//{
//	Queue<int> q;
//	//vector����ʵ�ֶ��У�û��pop_front�ӿ�
//	//Queue<int, list<int>> q;
//	q.push(1);
//	q.push(2);
//	q.push(3);
//	q.push(4);
//	q.push(5);
//	while (!q.empty())
//	{
//		cout << q.front() << " ";
//		q.pop();
//	}
//	cout << endl;
//}



////ʹ��˫�˶���,vector,listʵ��ջ,Ĭ��ʹ��deque
//template <class T,class Container=deque<T>>
//class Stack
//{
//	// size,empty,back,push_back,pop_back
//public:
//	void push(const T& val)
//	{
//		_c.push_back(val);
//	}
//	void pop()
//	{
//		_c.pop_back();
//	}
//	T& top()
//	{
//		return _c.back();
//	}
//	size_t size() const
//	{
//		return _c.size();
//	}
//	bool empty() const
//	{
//		return _c.empty();
//	}
//
//private:
//	Container _c;
//};
//
//void test()
//{
//	Stack<int> st;
//	//Stack<int, vector<int>> st;
//	//Stack<int, list<int>> st;
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	st.push(4);
//	while (!st.empty())
//	{
//		cout << st.top() << " ";
//		st.pop();
//	}
//	cout << endl;
//}




////˫�˶���ʵ��
////ʵ�ִ�ѽṹ
//template <class T>
//class PriorityQueue
//{
//public:
//	//�ѣ����µ���
//	void shiftDown()
//	{
//		int parent = 0;
//		int child = 2 * parent + 1;
//		while (child < arr.size())
//		{
//			if (child + 1 < arr.size() && arr[child] < arr[child + 1])
//				child++;
//			if (arr[parent] < arr[child])
//			{
//				swap(arr[parent], arr[child]);
//
//				//����λ��
//				parent = child;
//				child = 2 * parent + 1;
//			}
//			else
//				break;
//		}
//	}
//
//	//���ϵ���
//	void shiftUp(int child)
//	{
//		int parent = (child - 1) / 2;
//		while (child > 0)
//		{
//			if (arr[parent] < arr[child])
//			{
//				swap(arr[parent], arr[child]);
//
//				//����λ��
//				child = parent;
//				parent = (child - 1) / 2;
//			}
//			else
//				break;
//		}
//	}
//
//	void push(const T& val)
//	{
//		//β��
//		arr.push_back(val);
//		//���ϵ���
//		shiftUp(arr.size() - 1);
//	}
//
//	void pop()
//	{
//		//����
//		swap(arr[0], arr[arr.size() - 1]);
//		//βɾ
//		arr.pop_back();
//		//���µ���
//		shiftDown();
//	}
//
//	T& top()
//	{
//		return arr.front();
//	}
//
//	size_t size() const
//	{
//		return arr.size();
//	}
//	bool empty() const
//	{
//		return arr.empty();
//	}
//private:
//	vector<T> arr;
//};

//void test()
//{
//	//Ĭ�ϴ��ʵ��
//	PriorityQueue<int> pq;
//	//С��
//	//priority_queue<int, vector<int>, greater<int>> pq;
//	pq.push(100);
//	pq.push(1);
//	pq.push(125);
//	pq.push(10);
//	pq.push(0);
//	for (int i = 0; i < 1000; i++)
//	{
//		pq.push(i);
//	}
//	while (!pq.empty())
//	{
//		cout << pq.top() << " ";
//		pq.pop();
//	}
//	cout << endl;
//}






//�Զ�������
//class A
//{
//public:
//	A(int a=1)
//		:_a(a)
//	{}
//	//��ѱȽ�
//	bool operator<(const A& a) const
//	{
//		return _a < a._a;
//	}
//	//С�ѱȽ�
//	bool operator>(const A& a) const
//	{
//		return _a > a._a;
//	}
//public:
//	int _a;
//};
//
//void test()
//{
//	//���ȼ����д���Զ������ͣ���Ҫ�Զ�������֧�ֱȽϵĲ���
//	//priority_queue<A> pq;  //���
//	priority_queue<A, vector<A>, greater<A>> pq;  //С��
//	pq.push(A(1));
//	pq.push(A(10));
//	pq.push(A(15));
//	pq.push(A(2));
//	pq.push(A(0));
//	while (!pq.empty())
//	{
//		cout << pq.top()._a << " ";
//		pq.pop();
//	}
//	cout << endl;
//}


//void test()
//{
//	//Ĭ�ϴ��ʵ��
//	//priority_queue<int> pq;
//	//С��
//	priority_queue<int, vector<int>, greater<int>> pq;
//	pq.push(100);
//	pq.push(1);
//	pq.push(125);
//	pq.push(10);
//	pq.push(0);
//	while (!pq.empty())
//	{
//		cout << pq.top() << " ";
//		pq.pop();
//	}
//	cout << endl;
//
//}
int main()
{
	test();
	return 0;
}