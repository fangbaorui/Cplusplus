#define _CRT_SECURE_NO_WARNINGS
#include<functional>
#include<set>
#include<map>
#include<iostream>
using namespace std;

void test()
{
	//key值可以重复
	multimap<int, int> m;
	m.insert(make_pair(10, 10));
	m.insert(make_pair(10, 20));
	m.insert(make_pair(10, 30));
	m.insert(make_pair(10, 40));
	m.insert(make_pair(1, 50));
	m.insert(make_pair(10, 50));
	m.insert(make_pair(3, 50));
	m.insert(make_pair(17, 50));
	m.insert(make_pair(10, 10));

	for (auto& p : m)
	{
		cout << p.first << "-->" << p.second << endl;
	}

	//没有operator[]接口:数据不唯一

}


//void test()
//{
//	int arr[] = { 1,10,2,5,11,18,0,0,1,10,5 };
//	//multiset可以存放重复度数据
//	multiset<int> s(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	for (auto& e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	//set会去重
//	set<int> s1(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	for (auto& a : s1)
//	{
//		cout << a << " ";
//	}
//	cout << endl;	
//}


//void test()
//{
//	map<int, int> m;
//	//插入的类型为pair对象
//	//两种常见的插入方式
//	//1.调用pair构造函数创建对象  
//	auto ret = m.insert(pair<int, int>(1, 1));  //插入成功
//	cout << ret.first->first << "-->" << ret.first->second << "insert:"<<ret.second << endl;
//	//2.调用make_pair函数创建对象
//	ret = m.insert(make_pair(2, 2));  //插入成功
//	cout << ret.first->first << "-->" << ret.first->second << "insert:" <<ret.second<<endl;
//
//	ret = m.insert(make_pair(2, 3)); //k值已经存在，插入失败
//	cout << ret.first->first << "-->" << ret.first->second << "insert:" << ret.second << endl;
//
//	//删除k为2的值
//	size_t num = m.erase(2);
//	cout << num << endl;
//	cout << m.erase(2) << endl; //已经被删除了
//
//	//查找按照key值查找
//	auto it = m.find(1);
//	cout << it->first << it->second << endl; // 1 1
//	//查找失败，返回end迭代器
//	it = m.find(10);
//	cout << (it == m.end()) << endl;  //1
//}



//void test()
//{
//	pair<int, int> arr[] = { pair<int,int>(5,5),pair<int,int>(1,2),
//		pair<int,int>(3,3),pair<int,int>(0,0),pair<int,int>(1,3)};
//	map<int, int> m2(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	
//	//访问operator[]
//	cout << m2[3] << endl;  //3
//	cout << m2[1] << endl;  //2
//	//修改
//	m2[1] = 100;    //1-->100
//
//	//插入一个新的键值对
//	m2[100] = 100;  //100-->0 --  100-->100
//	cout << m2[100] << endl;
//
//	//at接口执行的操作，如果key不存在，抛异常
//	//cout << m2.at(1000) << endl;
//}



//template<class T1,class T2>
//void printMap(const map<T1,T2>& m)
//{
//	//map中的数据是pair
//	//迭代器访问的顺序：按照key的中序遍历
//	map<T1, T2>::const_iterator it = m.begin();
//	while (it != m.end())
//	{
//		//不能直接输出pair对象
//		//cout<<it;
//		cout << it->first << "-->" << it->second << endl;
//		++it;
//	}
//}

//template <class T1, class T2>
//void printMap2(const map<T1, T2>& m)
//{
//	//map中的数据是pair
//	//迭代器访问的顺序：按照key的中序遍历
//	map<T1, T2>::const_reverse_iterator it = m.rbegin();
//	while (it != m.rend())
//	{
//		//不能直接输出pair对象
//		//cout<<it;
//		cout << it->first << "-->" << it->second << endl;
//		++it;
//	}
//}
//void test()
//{
//	map<int, int> m;
//	pair<int, int> arr[] = { pair<int,int>(5,5),pair<int,int>(1,2),
//	pair<int,int>(3,3),pair<int,int>(0,0),pair<int,int>(1,3)};
//	
//	//map中key不能重复，value可以重复
//	map<int, int> m2(arr,arr+sizeof(arr)/sizeof(arr[0]));
//	//printMap(m2);
//	//printMap2(m2);
//
//	/*map<int, int, greater<int>> m3(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	for (auto& p : m3)
//	{
//		cout << p.first << "-->" << p.second << endl;
//	}*/
//
//	//map的迭代器可以修改value，不能修改key
//	/*auto& it = m2.begin();
//	it->second = 1000;*/
//
//
//}




//template<class T>
//void printSet(const set<T>& s)
//{
//	for (auto& e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
//
//template<class T>
//void printSet2(const set<T,greater<T>>& s)
//{
//	for (auto& e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
//
//void test()
//{
//	set<int> s;
//	int arr[] = { 10,2,3,4,1 };
//	set<int, greater<int>> s3(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	printSet2(s3);
//}

//void test()
//{
//	set<int> s;
//	int arr[] = { 10,2,3,4,1 };
//	//set不存放重复数据，天然去重
//	set<int> s2(arr, arr + sizeof(arr) / sizeof(arr[0]));
//
//	//set迭代器遍历，数据天然有序：本质迭代器进行中序遍历
//	set<int>::iterator it = s2.begin();
//	while (it != s2.end())
//	{
//		//set迭代器不支持修改
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	cout << "reverse iterator:" << endl;
//	set<int>::reverse_iterator rit = s2.rbegin();
//	while (rit != s2.rend())
//	{
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//
//	//insert：插入失败：已有数据的迭代器，false
//	pair<set<int>::iterator, bool> ret = s2.insert(10);
//	cout << ret.second << " "<< *ret.first << endl;
//	printSet(s2);
//	
//	//insert：插入成功：新数据迭代器，true
//	ret = s2.insert(100);
//	cout << ret.second << " " << *ret.first << endl;
//	printSet(s2);
//
//	//iterator insert(iterator position,const value_type& val);
//	//insert(iterator,val):iterator只是一个位置建议，最终数据的位置不指定在指定位置之前
//	s2.insert(ret.first, 0);
//	printSet(s2);
//
//	//插入一个数组的区间元素
//	int arr2[] = { 12,9,6,18,39,12,9,6};
//	s2.insert(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
//	printSet(s2);
//
//	int num = s2.erase(39);
//	printSet(s2);
//	cout << num << endl; //1,删除一个
//	num = s2.erase(39);
//	cout << num << endl;  //0，没有。不能删除
//	s2.erase(s2.begin());
//	//erase:不能传非法位置：比如end
//	//s2.erase(s2.end());
//	printSet(s2);
//
//	s2.erase(++s2.begin(), --s2.end()); //保留第一个和最后一个
//	printSet(s2);
//
//	auto iit = s2.find(1);
//	cout << (iit != s2.end()) << endl;//找到为1
//	iit = s2.find(10);
//	cout << (iit != s2.end()) << endl;//找不到返回0
//
//	cout << s2.count(100) << endl; //找到返回1
//	cout << s2.count(1000) << endl;//找不到返回0
//}

int main()
{
	test();
	return 0;
}
