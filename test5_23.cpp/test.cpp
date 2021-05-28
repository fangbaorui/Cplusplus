#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
enum STATE
{
	EXIST,
	DELETE,
	EMPTY
};
//哈希表：线性探测
//线性探测：从计算的哈希位置开始，找第一个空闲的位置，存放数据
template <class K,class V>
struct HashNode
{
	pair<K, V> _kv;
	STATE _state = EMPTY;
};

//顺序表实现hash
template <class K, class V>
class HashTable
{
public:
	typedef HashNode<K, V> Node;
	HashTable(size_t n = 10)
		:_hTable(n)
		,_size(0)
	{}

	bool insert(const pair<K, V>& kv)
	{
		//0.检查容量
		checkCapacity();
		//1.计算哈希位置
		int idx = kv.first % _hTable.size();

		//2.判断key是否存在
		while (_hTable[idx]._state != EMPTY)
		{
			//如果当前位置数据有效，且key相同，插入失败
			if (_hTable[idx]._state == EXIST
				&& kv.first == _hTable[idx]._kv.first)
				return false;

			//继续搜索
			++idx;
			if (idx == _hTable.size())
				idx = 0;
		}

		//插入
		_hTable[idx]._kv = kv;
		_hTable[idx]._state = EXIST;
		++_size;
		return true;
	}

	void checkCapacity()
	{
		//负载因子：<1,差不多为0.7的时候增容
		if (_hTable.size() == 0 || _size * 10 / _hTable.size() >= 7)
		{
			//开新表
			int newC = _hTable.size() == 0 ? 10 : 2 * _hTable.size();
			HashTable<K, V> newHt(newC);

			for (size_t i = 0; i < _hTable.size(); i++)
			{
				//插入状态为exist的数据
				if (_hTable[i]._state == EXIST)
				{
					newHt.insert(_hTable[i]._kv);
				}
			}
			Swap(newHt);
		}
	}

	void Swap(HashTable<K, V>& Ht)
	{
		swap(_hTable, Ht._hTable);
		swap(_size, Ht._size);
	}

	Node* find(const K& key)
	{
		//计算位置
		int idx = key % _hTable.size();
		while (_hTable[idx]._state != EMPTY)
		{
			if (_hTable[idx]._state == EXIST &&
				key == _hTable[idx]._kv.first)
				return &_hTable[idx];
			//继续往后找
			++idx;
			//如果到了表长，从头开始找
			if (idx = _hTable.size())
				idx = 0;
		}
		return nullptr;
	}

	bool erase(const K& key)
	{
		Node* node = find(key);
		if (node)
		{
			--_size;
			node->_state = DELETE;
			return true;
		}
		return false;
	}

private:
	vector<Node> _hTable;
	size_t _size; //有效元素个数
};

void test()
{
	HashTable<int, int> ht;
	ht.insert(make_pair(1, 1));
	ht.insert(make_pair(14, 14));
	ht.insert(make_pair(16, 16));
	ht.insert(make_pair(11, 11));
	ht.insert(make_pair(2, 1));
	ht.insert(make_pair(3, 14));
	ht.insert(make_pair(5, 16));
	ht.insert(make_pair(7, 11));
	ht.insert(make_pair(8, 140));
	ht.insert(make_pair(13, 1));

	cout << ht.find(11) << endl;
	cout << ht.find(100) << endl;

	cout << ht.erase(11) << endl;
	cout << ht.erase(100) << endl;
}

int main()
{
	test();
	return 0;
}