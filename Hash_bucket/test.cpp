#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
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
		,_next(nullptr)
	{}
};

template<class K, class V, class KeyOfValue>
class HTable
{
public:
	typedef HashNode<V> Node;
	HTable(int n = 10)
		:_ht(n)
		, _size(0)
	{}

	bool insert(const V& val)
	{
		//0.检查容量
		checkCapacity();
		//1.计算hash位置
		KeyOfValue kov;
		int idx = kov(val) % _ht.size();
		//2.查找
		Node* cur = _ht[idx];
		while (cur)
		{
			if (kov(cur->_val) == kov(val))
			{
				//key重复
				return false;
			}
			cur = cur->_next;
		}
		//3.插入
		cur = new Node(val);
		cur->_next = _ht[idx];
		_ht[idx] = cur;
		++_size;
		return true;
	}

	void checkCapacity()
	{
		if (_size == _ht.size())
		{
			int newC = _size == 0 ? 10 : 2 * _size;

			//创建新的指针数组
			vector<Node*> newHt(newC);

			KeyOfValue kov;
			//遍历旧表
			for (int i = 0; i<_ht.size(); i++)
			{
				Node* cur = _ht[i];
				//遍历单链表
				while (cur)
				{
					Node* next = cur->_next;
					int idx = kov(cur->_val) % newHt.size();
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

void test()
{

}

int main()
{
	test();
	return 0;
}