#define _CRT_SECURE_NO_WARNINGS
#include<unordered_map>
#include<unordered_set>
#include<iostream>
#include<map>
#include<set>
using namespace std;

void test()
{
	//操作性能为o（1），map性能为o（log N）
	//unordered_map<int, int> m;
	unordered_multimap<int, int> m;
	//map<int, int> m;
	m.insert(make_pair(1, 1));
	//m[2] = 2;

	for (int i = 0; i < 10; i++)
	{
		//m[i] = i; 
		m.insert(make_pair(i, i));
	}
	for (int i = 0; i < 10; i++)
	{
		//m[i] = i; 
		m.insert(make_pair(i, i));
	}

	//unordered_map/set只有正向迭代器
	//unordered_map<int, int>迭代器遍历不是有序的
	unordered_map<int, int>::iterator it = m.begin();
	//auto it = m.begin();
	while (it != m.end())
	{
		cout << it->first << " ";
		++it;
	}
	cout << endl;

	cout << "m.equal_range" << endl;
	auto range = m.equal_range(3);
	it = range.first;
	while (it != range.second)
	{
		cout << it->first << " ";
		++it;
	}
	cout << endl;
}

int main()
{
	test();
	return 0;
}
