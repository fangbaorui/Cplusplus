#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include<iostream>
using namespace std;
//listʵ�֣���ͷ˫��ѭ������
template <class T>
struct ListNode
{
	T _data;
	ListNode<T>* _next;
	ListNode<T>* _prev;

	ListNode(const T& val = T())
		:_data(val)
	    ,_next(nullptr)
		,_prev(nullptr)
	{}
};

//����������
template <class T,class Ref,class Ptr>
struct ListIterator
{
	typedef ListNode<T> Node;
	typedef ListIterator<T, Ref, Ptr> Self;
	//��װ�ڵ�
	Node* _node;

	ListIterator(Node* node)
		:_node(node)
	{}

	//*iterator
	//T& operator*()
	Ref operator*()
	{
		return _node->_data;
	}

	//++iterator
	Self& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	//iterator++
	Self operator++(int)
	{
		//ListIterator<T> tmp(_node);
		//ListIterator<T> tmp(*this);
		Self tmp = *this;
		_node = _node->_next;
		return tmp;

	}
	bool operator!=(const Self& it)
	{
		return _node != it._node;
	}

	//it->  --->  T* --->  ->
	//������TΪ�Զ������ͣ��Ұ��������Ա
	//      ͨ��->����ÿһ����Ա
	//T* operator->()
	Ptr operator->()
	{
		return &_node->_data;
	}

	bool operator==(const Self& it)
	{
		return _node == it._node;
		//�����
		//it->_node;
	}

	Self& operator--()
	{
		_node = _node->_prev;
		return *this;
	}
};

////����������
//template <class T>
//struct ConstListIterator
//{
//	typedef ListNode<T> Node;
//	//��װ�ڵ�
//	Node* _node;
//
//	ConstListIterator(Node* node)
//		; _node(node)
//	{}
//
//	//*iterator
//	const T& operator*()
//	{
//		return _node->_data;
//	}
//
//	//++iterator
//	ConstListIterator& operator++()
//	{
//		_node = _node->_next;
//		return *this;
//	}
//
//	//iterator++
//	ConstListIterator<T> operator++(int)
//	{
//		//ListIterator<T> tmp(_node);
//		//ListIterator<T> tmp(*this);
//		ConstListIterator<T> tmp = *this;
//		_node = _node->_next;
//		return tmp;
//
//	}
//	bool operator!=(const ConstListIterator<T>& it)
//	{
//		return _node != it._node;
//	}
//
//	//it->  --->  T* --->  ->
//	//������TΪ�Զ������ͣ��Ұ��������Ա
//	//      ͨ��->����ÿһ����Ա
//	const T* operator->()
//	{
//		return &_node->_data;
//	}
//
//	bool operator==(const ConstListIterator<T>& it)
//	{
//		return _node == it._node;
//		//�����
//		//it->_node;
//	}
//
//	ConstListIterator<T>& operator--()
//	{
//		_node = _node->_prev;
//		return *this;
//	}
//};

struct A
{
	A(int a=1)
		:_a(a)
	{}
	int _a;
	int _b;
};

template <class T>
class List
{
public:
	typedef ListNode<T> Node;
	typedef Node* pNode;

	//iterator��const_iterator���Ͳ�ͬ
	typedef ListIterator<T,T&,T*> iterator;
	//typedef ConstListIterator<T> const_iterator;
	typedef ListIterator<T, const T&, const T*> const_iterator;

	iterator begin()
	{
		//����һ������������node��Աָ��header->next
		iterator it(_header->_next);
		return it;
		//return iterator(_header->_next);
	}

	iterator end()
	{
		return iterator(_header);
	}

	const_iterator begin() const
	{
		return const_iterator(_header->_next);
	}

	const_iterator end() const
	{
		return const_iterator(_header);
	}

	List()
		:_header(new Node())
	{
		//ѭ���ṹ
		_header->_next = _header->_prev = _header;
	}

	List(size_t n, const T& val = T())
		:_header(new Node())
	{
		_header->_next = _header->_prev = _header;
		for (size_t i = 0; i < n; i++)
		{
			pushBack(val);
		}
	}

	template<class inputIterator>
	List(inputIterator first, inputIterator last)
		:_header(new Node())
	{
		//ѭ���ṹ
		_header->_next = _header->_prev = _header;
		while (first != last)
		{
			pushBack(*first);
			++first;
		}
	}

	void pushBack(const T& val)
	{
		//Node* prev = _header->_prev;
		//Node* newNode = new Node(val);

		//prev->_next = newNode;
		//newNode->_prev = prev;

		//newNode->_next = _header;
		//_header->_prev = newNode;

		insert(end(), val);
	}

	void pushFront(const T& val)
	{
		insert(begin(), val);
	}

	//������ָ��Ľڵ��ͷţ�������ʧЧ
	//���µ�����
	//����ֵ��iterator --- > ��ɾ��Ԫ�ص���һ��λ��
	iterator erase(iterator pos)
	{
		//�ж��Ƿ�Ϊ��Чλ��
		if (pos != end())
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;

			delete cur;

			prev->_next = next;
			next->_prev = prev;
			return iterator(next);
		}
		return pos;
	}

	void popBack()
	{
		erase(--end());
	}

	void popFront()
	{
		erase(begin());
	}

	void insert(iterator pos, const T& val)
	{
		Node* cur = pos._node;
		Node* prev = cur->_prev;

		Node* newNode = new Node (val);

		prev->_next = newNode;
		newNdoe->_prev = prev;

		newNode->_next = cur;
		cur->_prev = newNdoe;
	}

	~List()
	{
		if (_header)
		{
			Node* node = _header->_next;
			while (node != _header)
			{
				Node* next = node->_next;
				delete node;
				node = next;
			}
			delete _header;
			_header = nullptr;
		}
	}

	//���
	List(const List<T>& lst)
		:_header(new Node())
	{
		//ѭ���ṹ
		_header->_prev = _header->_next = _header;
		/*Node* cur = lst._header->_next;
		while (cur != _header)
		{
			Node* newNode = new Node(cur->_data);
			cur = cur->_next;
		}*/

		for (auto& e : lst)
		{
			pushBack(e);
		}
	}

	List<T>& operator=(const List<T>& lst);

private:
	ListNode<T>* _header;
};

template <class T>
void printList(const List<T>& lst)
{
	List<T>::const_iterator it = lst.begin();
	while (it != lst.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}


//void test()
//{
//	List<int> lst;
//	lst.pushBack(1);
//	lst.pushBack(2);
//	lst.pushBack(3);
//	lst.pushBack(4);
//
//	List<int>::iterator it = lst.begin();
//	while (it != lst.end())   //it.operator!=(lst.end())
//	{
//		cout << *it << " ";   //it.operator*()
//		++it;   //it.operator++()
//		it++;
//	}
//	cout << endl;
//
//	it = lst.begin();
//	while (it != lst.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//}


//void test()
//{
//	List<int> lst;
//	lst.pushBack(1);
//	lst.pushBack(2);
//	lst.pushBack(3);
//	lst.pushBack(4);
//	lst.pushBack(5);
//
//	List<int> lst2((size_t)10, 5);  //10��5
//
//	string str = "1234567890";
//	List<char> lst3(str.begin(), str.end());
//}


//void test()
//{
//	List<A> lst;
//	lst.pushBack(1);
//	lst.pushBack(2);
//	lst.pushBack(3);
//	lst.pushBack(4);
//
//	List<A>::iterator it = lst.begin();
//	while (it != lst.end())
//	{
//		cout << *it << " ";
//		(*it)._a = 1;
//		(*it)._b = 2;
//		it->_a;
//		it.operator->()->_a;
//
//		A a(100);
//		A* pa = &a;
//		pa->_a;
//		pa->_b;
//
//		(*pa)._a;
//		(*pa)._b;
//		++it;
//	}
//}

//void test()
//{
//	List<int> lst;
//	lst.pushBack(1);
//	lst.pushBack(2);
//	lst.pushBack(3);
//	lst.pushBack(4);
//	lst.pushBack(5);
//
//	//for (auto& e : lst)
//	//{
//	//	cout << e << " ";
//	//	e = 100;
//	//}
//	//cout << endl;
//	//printList(lst);
//
//	List<int>::iterator it = lst.begin();
//	while (it != lst.end())
//	{
//		if (*it % 2 == 0)
//			lst.erase(it);
//		else
//			++it;
//	}
//	printList(lst);
//}


void test()
{
	List<int> lst;
	lst.pushBack(1);
	lst.pushBack(2);
	lst.pushBack(3);
	lst.pushBack(4);
	lst.pushBack(5);
	printList(lst);

	lst.pushFront(0);
	printList(lst);

	lst.popFront();
	printList(lst);

	lst.popBack();
	printList(lst);

	List<int> copy(lst);
	printList(lst);


int main()
{
	test();
	return 0;
}