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

	//��ȡԪ��
	int get(int key)
	{
		//�ҵ�Ԫ�ؼ�¼������ɾ��Ԫ�أ��ٽ���ͷ��
		auto hashit = _hashmap.find(key);
		//�ҵ���
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
			//û�ҵ�
			return -1;
		}
	}

	//����Ԫ��
	void put(int key, int value)
	{
		//���û�����ݣ�����в�������
		//��������ݣ���������
		auto hashit = _hashmap.find(key);
		//���ݲ�����
		if (hashit == _hashmap.end())  
		{
			//��������ʱ������Ѿ��������ޣ���ɾ����β�����ݺ�hashmap�е�����
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
			//������ݴ���
			auto listit = hashit->second;
			pair<int, int> kv = *listit;
			kv.second = value;

			_list.erase(listit);
			_list.push_front(kv);
			_hashmap[key] = _list.begin();
		}
	}

private:
	list<pair<int, int>> _list;   //������ù���������ͷ���ƶ�
	size_t _capacity;            //������С�����������򻻳�
	unordered_map<int, list<pair<int, int>>::iterator> _hashmap;
};