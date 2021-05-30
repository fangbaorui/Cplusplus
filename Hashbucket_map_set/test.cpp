#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<unordered_set>
#include<vector>
#include<string>
using namespace std;
//开散列，哈希桶
//单链表的节点
template<class V>
struct HashNode
{
	V _val;
	HashNode<V>* _next;

	HashNode(const V& val)
		:_val(val)
		, _next(nullptr)
	{}
};


//哈希表的前置声明
template<class K, class V, class KeyOfValue, class HashFun = HashFun<K>>
class HTable;

//哈希表迭代器：自定义类型
//通过封装单链表的节点实现
template <class K, class V, class KeyOfValue, class HashFun = HashFun<K>>
struct HashIterator
{
	typedef HashIterator<K, V, KeyOfValue, HashFun> Self;
	typedef HTable<K, V, KeyOfValue, HashFun> HT;
	//成员：节点指针,哈希表指针
	typedef HashNode<V> Node;
	HT* _hPtr;

	Node* _node;
	HashIterator(Node* node, HT* hPtr)
		:_node(node)
		, _hPtr(hPtr)
	{}

	V& operator*()
	{
		return _node->_val;
	}

	V* operator->()
	{
		return &_node->_val;
	}

	bool operator!=(const Self& it)
	{
		return _node != it._node;
	}

	Self& operator++()
	{
		if (_node->_next)
		{
			_node = _node->_next;
		}
		else
		{
			//查找下一个非空链表的头结点
			//计算当前节点在哈希表中的位置
			KeyOfValue kov;
			HashFun hfun;
			size_t idx = hfun(kov(_node->_val)) % _hPtr->_ht.size();
			//从下一个哈希位置开始查找
			++idx;
			for (; idx < _hPtr->_ht.size(); ++idx)
			{
				if (_hPtr->_ht[idx])
				{
					//找到了下一个非空链表
					_node = _hPtr->_ht[idx];
					break;
				}
			}
			//没有有效节点
			if (idx == _hPtr->_ht.size())
				_node = nullptr;
		}
		return *this;
	}
};

//HashFun:把类型不是数值的key，转换成一个数值类型
template<class K, class V, class KeyOfValue, class HashFun>
class HTable
{
public:
	typedef HashNode<V> Node;
	typedef HashIterator<K, V, KeyOfValue,HashFun> iterator;

	//把迭代器声明为友元类
	template <class K, class V, class KeyOfValue, class HashFun>
	friend struct HashIterator;

	HTable(int n = 10)
		:_ht(n)
		, _size(0)
	{}

	iterator begin()
	{
		//第一个非空链表的头结点
		for (size_t i = 0; i < _ht.size(); i++)
		{
			if (_ht[i])
			{
				return iterator(_ht[i], this);
			}
		}
		return iterator(nullptr, this);
	}

	iterator end()
	{
		return iterator(nullptr, this);
	}

	pair<iterator,bool> insert(const V& val)
	//bool insert(const V& val)
	{
		//0.检查容量
		checkCapacity();
		//1.计算hash位置
		KeyOfValue kov;
		HashFun hfun;
		int idx = hfun(kov(val)) % _ht.size();
		//2.查找
		Node* cur = _ht[idx];
		while (cur)
		{
			if (kov(cur->_val) == kov(val))
			{
				//key重复
				//return false;
				return make_pair(iterator(cur, this), false);
			}
			cur = cur->_next;
		}
		//3.插入
		cur = new Node(val);
		cur->_next = _ht[idx];
		_ht[idx] = cur;
		++_size;
		//return true;
		return make_pair(iterator(cur, this), true);
	}

	
	size_t GetNextPrime(size_t prime)
	{
		const int PRIMECOUNT = 28;
		const size_t primeList[PRIMECOUNT] =
		{
		 53ul, 97ul, 193ul, 389ul, 769ul,
		 1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
		 49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
		 1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
		 50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
		 1610612741ul, 3221225473ul, 4294967291ul
		};

		size_t i = 0;
		for (; i < PRIMECOUNT; ++i)
		{
			if (primeList[i] > prime)
				return primeList[i];
		}

		return primeList[PRIMECOUNT - 1];
	}

	void checkCapacity()
	{
		if (_size == _ht.size())
		{
			//int newC = _size == 0 ? 10 : 2 * _size;

			size_t newC = GetNextPrime(_ht.size());
			//创建新的指针数组
			vector<Node*> newHt(newC);

			KeyOfValue kov;
			HashFun hfun;
			//遍历旧表
			for (size_t i = 0; i < _ht.size(); i++)
			{
				Node* cur = _ht[i];
				//遍历单链表
				while (cur)
				{
					Node* next = cur->_next;
					int idx = hfun(kov(cur->_val)) % newHt.size();
					//头插
					cur->_next = newHt[idx];
					newHt[idx] = cur;
					//往下找
					cur = next;
				}
				//旧表置空
				_ht[i] = nullptr;
			}
			//新表，旧表交换
			swap(_ht, newHt);
		}
	}
	Node* find(const K& key);
	bool Erase(const K& key);

private:
	//指针数组
	vector<Node*> _ht;
	int _size;
};

template <class K>
struct HashFun
{
	size_t operator()(const K& key)
	{
		return key;
	}
};

template<>
struct HashFun<string>
{
	size_t operator()(const string& key)
	{
		size_t hash = 0;
		for (const auto& ch : key)
		{
			hash = hash * 131 + ch;
		}
		return hash;
	}
};


struct HashFunString
{
	size_t operator()(const string& key)
	{
		size_t hash = 0;
		for (const auto& ch : key)
		{
			hash = hash * 131 + ch;
		}
		return hash;
	}
};


class A
{
public:
	int _a;
	string _b;
	double _d;

	bool operator==(const A& a) const
	{
		return _a == a._a &&
			_b == a._b;
	}
};

struct hashFunA
{
	size_t operator()(const A& a)
	{
		return a._a + a._d;
	}
};

template <class K,class V>
class Map
{
	struct MapKeyOfValue
	{
		const K& operator()(const pair<K, V>& val)
		{
			return val.first;
		}
	};
public:
	typedef typename HTable<K, pair<K, V>, MapKeyOfValue>::iterator iterator;

	pair<iterator, bool> insert(const pair<K, V>& val)
	{
		return _ht.insert(val);
	}

	iterator begin()
	{
		return _ht.begin();
	}

	iterator end()
	{
		return _ht.end();
	}

	V& operator[](const K& key)
	{
		pair<iterator, bool> ret = _ht.insert(make_pair(key, V()));
		return ret.first->second;
	}

private:
	HTable<K, pair<K, V>, MapKeyOfValue> _ht;
};


//set
template <class K>
class Set
{
	struct SetKeyOfValue
	{
		const K& operator()(const K& key)
		{
			return key;
		}
	};

public:

	typedef typename HTable<K, K, SetKeyOfValue>::iterator iterator;

	iterator begin()
	{
		return _ht.begin();
	}

	iterator end()
	{
		return _ht.end();
	}

	pair<iterator,bool> insert(const K& key)
	{
		return _ht.insert(key);
	}
private:
	HTable<K, K, SetKeyOfValue> _ht;
};

void test()
{
	Set<string> s;
	s.insert("1234");

	Set<int> s1;
	s1.insert(1);

	unordered_set<A,hashFunA> s2;
	s2.insert(A());
}



//void test()
//{
//	Map<int, int> m;
//	m.insert(make_pair(1, 1));
//	m[20] = 20;
//	m[30] = 30;
//	m[1] = 100;
//	m[30] = 300;
//	m.insert(make_pair(20, 200));
//
//	Map<int, int>::iterator it = m.begin();
//	while (it != m.end())
//	{
//		cout << it->first << "--->" << it->second << " ";
//		++it;
//	}
//	cout << endl;
//
//	cout << "范围for" << endl;
//	for (const auto& p : m)
//	{
//		cout << p.first << "--->" << p.second << " ";
//	}
//}



//void test()
//{
//	Set<int> s;
//	s.insert(1);
//	s.insert(2);
//	s.insert(3);
//	s.insert(4);
//	s.insert(13);
//	s.insert(44);
//	s.insert(45);
//	s.insert(17);
//	s.insert(6);
//	s.insert(16);
//	s.insert(11);
//
//	Set<int>::iterator it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//
//	for (const auto& e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
int main()
{
	test();
	return 0;
}




//#include<iostream>
//#include<vector>
//using namespace std;
////开散列，哈希桶
////单链表的节点
//template<class V>
//struct HashNode
//{
//	V _val;
//	HashNode<V>* _next;
//
//	HashNode(const V& val)
//		:_val(val)
//		, _next(nullptr)
//	{}
//};
//
//
////哈希表的前置声明
//template<class K, class V, class KeyOfValue>
//class HTable;
//
////哈希表迭代器：自定义类型
////通过封装单链表的节点实现
//template <class K, class V, class KeyOfValue>
//struct HashIterator
//{
//	typedef HashIterator<K, V, KeyOfValue> Self;
//	typedef HTable<K, V, KeyOfValue> HT;
//	//成员：节点指针,哈希表指针
//	typedef HashNode<V> Node;
//	HT* _hPtr;
//
//	Node* _node;
//	HashIterator(Node* node,HT* hPtr)
//		:_node(node)
//		,_hPtr(hPtr)
//	{}
//
//	V& operator*()
//	{
//		return _node->_val;
//	}
//
//	V& operator->()
//	{
//		return &_node->_val;
//	}
//
//	bool operator!=(const Self& it)
//	{
//		return _node != it._node;
//	}
//
//	Self& operator++()
//	{
//		if (_node->_next)
//		{
//			_node = _node->_next;
//		}
//		else
//		{
//			//查找下一个非空链表的头结点
//			//计算当前节点在哈希表中的位置
//			KeyOfValue kov;
//			size_t idx = kov(_node->_val) % _hPtr->_ht.size();
//		    //从下一个哈希位置开始查找
//			++idx;
//			for (; idx < _hPtr->_ht.size(); ++idx)
//			{
//				if (_hPtr->_ht[idx])
//				{
//					//找到了下一个非空链表
//					_node = _hPtr->_ht[idx];
//					break;
//				}
//			}
//			//没有有效节点
//			if (idx == _hPtr->_ht.size())
//				_node = nullptr;
//		}
//		return *this;
//	}
//};
//
//
//template<class K, class V, class KeyOfValue>
//class HTable
//{
//public:
//	typedef HashNode<V> Node;
//	typedef HashIterator<K, V, KeyOfValue> iterator;
//	
//	//把迭代器声明为友元类
//	template <class K, class V, class KeyOfValue>
//	friend struct HashIterator;
//	
//	HTable(int n = 10)
//		:_ht(n)
//		, _size(0)
//	{}
//
//	iterator begin()
//	{
//		//第一个非空链表的头结点
//		for (size_t i = 0; i < _ht.size(); i++)
//		{
//			if (_ht[i])
//			{
//				return iterator(_ht[i], this);
//			}
//		}
//		return iterator(nullptr, this);
//	}
//
//	iterator end()
//	{
//		return iterator(nullptr, this);
//	}
//
//	bool insert(const V& val)
//	{
//		//0.检查容量
//		checkCapacity();
//		//1.计算hash位置
//		KeyOfValue kov;
//		int idx = kov(val) % _ht.size();
//		//2.查找
//		Node* cur = _ht[idx];
//		while (cur)
//		{
//			if (kov(cur->_val) == kov(val))
//			{
//				//key重复
//				return false;
//			}
//			cur = cur->_next;
//		}
//		//3.插入
//		cur = new Node(val);
//		cur->_next = _ht[idx];
//		_ht[idx] = cur;
//		++_size;
//		return true;
//	}
//
//	void checkCapacity()
//	{
//		if (_size == _ht.size())
//		{
//			int newC = _size == 0 ? 10 : 2 * _size;
//
//			//创建新的指针数组
//			vector<Node*> newHt(newC);
//
//			KeyOfValue kov;
//			//遍历旧表
//			for (size_t i = 0; i < _ht.size(); i++)
//			{
//				Node* cur = _ht[i];
//				//遍历单链表
//				while (cur)
//				{
//					Node* next = cur->_next;
//					int idx = kov(cur->_val) % newHt.size();
//					//头插
//					cur->_next = newHt[idx];
//					newHt[idx] = cur;
//					//往下找
//					cur = next;
//				}
//				//旧表置空
//				_ht[i] = nullptr;
//			}
//			//新表，旧表交换
//			swap(_ht, newHt);
//		}
//	}
//	Node* find(const K& key);
//	bool Erase(const K& key);
//
//private:
//	//指针数组
//	vector<Node*> _ht;
//	int _size;
//};
//
//
////set
//template <class K>
//class Set
//{
//	struct SetKeyOfValue
//	{
//		const K& operator()(const K& key)
//		{
//			return key;
//		}
//	};
//
//public:
//
//	typedef typename HTable<K, K, SetKeyOfValue>::iterator iterator;
//
//	iterator begin()
//	{
//		return _ht.begin();
//	}
//
//	iterator end()
//	{
//		return _ht.end();
//	}
//
//	bool insert(const K& key)
//	{
//		return _ht.insert(key);
//	}
//private:
//	HTable<K, K, SetKeyOfValue> _ht;
//};
//
//void test()
//{
//	Set<int> s;
//	s.insert(1);
//	s.insert(2);
//	s.insert(3);
//	s.insert(4);
//	s.insert(13);
//	s.insert(44);
//	s.insert(45);
//	s.insert(17);
//	s.insert(6);
//	s.insert(16);
//	s.insert(11);
//
//	Set<int>::iterator it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//
//	for (const auto& e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}





