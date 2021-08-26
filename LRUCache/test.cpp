#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;
class LRUCache
{
public:
	LRUCache(int capacity)
		:_capacity(capacity)
	{}

	//获取元素
	int get(int key)
	{
		//找到元素记录下来，删除元素，再进行头插
		auto hashit = _hashmap.find(key);
		//找到了
		if (hashit != _hashmap.end())   
		{
			auto listit = hashit->second;
			pair<int, int> kv = *listit;
			
			_list.erase(listit);
			_list.push_front(kv);
			_hashmap[key] = _list.begin();
			return kv.second;
		}
		else
		{
			//没找到
			return -1;
		}
	}

	//插入元素
	void put(int key, int value)
	{
		//如果没有数据，则进行插入数据
		//如果有数据，跟新数据
		auto hashit = _hashmap.find(key);
		//数据不存在
		if (hashit == _hashmap.end())  
		{
			//插入数据时，如果已经到达上限，则删除表尾的数据和hashmap中的数据
			if (_list.size() >= _capacity)
			{
				_hashmap.erase(_list.back().first);
				_list.pop_back();
			}

			_list.push_front(make_pair(key, value));
			_hashmap[key] = _list.begin();
		}
		else
		{
			//如果数据存在
			auto listit = hashit->second;
			pair<int, int> kv = *listit;
			kv.second = value;

			_list.erase(listit);
			_list.push_front(kv);
			_hashmap[key] = _list.begin();
		}
	}

private:
	list<pair<int, int>> _list;   //将最近用过的往链表头部移动
	size_t _capacity;            //容量大小，超过容量则换出
	unordered_map<int, list<pair<int, int>>::iterator> _hashmap;
};