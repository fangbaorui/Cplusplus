#define _CRT_SECURE_NO_WARNINGS
#include<functional>
#include<set>
#include<map>
#include<iostream>
using namespace std;

void test()
{
	//keyֵ�����ظ�
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

	//û��operator[]�ӿ�:���ݲ�Ψһ

}


//void test()
//{
//	int arr[] = { 1,10,2,5,11,18,0,0,1,10,5 };
//	//multiset���Դ���ظ�������
//	multiset<int> s(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	for (auto& e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	//set��ȥ��
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
//	//���������Ϊpair����
//	//���ֳ����Ĳ��뷽ʽ
//	//1.����pair���캯����������  
//	auto ret = m.insert(pair<int, int>(1, 1));  //����ɹ�
//	cout << ret.first->first << "-->" << ret.first->second << "insert:"<<ret.second << endl;
//	//2.����make_pair������������
//	ret = m.insert(make_pair(2, 2));  //����ɹ�
//	cout << ret.first->first << "-->" << ret.first->second << "insert:" <<ret.second<<endl;
//
//	ret = m.insert(make_pair(2, 3)); //kֵ�Ѿ����ڣ�����ʧ��
//	cout << ret.first->first << "-->" << ret.first->second << "insert:" << ret.second << endl;
//
//	//ɾ��kΪ2��ֵ
//	size_t num = m.erase(2);
//	cout << num << endl;
//	cout << m.erase(2) << endl; //�Ѿ���ɾ����
//
//	//���Ұ���keyֵ����
//	auto it = m.find(1);
//	cout << it->first << it->second << endl; // 1 1
//	//����ʧ�ܣ�����end������
//	it = m.find(10);
//	cout << (it == m.end()) << endl;  //1
//}



//void test()
//{
//	pair<int, int> arr[] = { pair<int,int>(5,5),pair<int,int>(1,2),
//		pair<int,int>(3,3),pair<int,int>(0,0),pair<int,int>(1,3)};
//	map<int, int> m2(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	
//	//����operator[]
//	cout << m2[3] << endl;  //3
//	cout << m2[1] << endl;  //2
//	//�޸�
//	m2[1] = 100;    //1-->100
//
//	//����һ���µļ�ֵ��
//	m2[100] = 100;  //100-->0 --  100-->100
//	cout << m2[100] << endl;
//
//	//at�ӿ�ִ�еĲ��������key�����ڣ����쳣
//	//cout << m2.at(1000) << endl;
//}



//template<class T1,class T2>
//void printMap(const map<T1,T2>& m)
//{
//	//map�е�������pair
//	//���������ʵ�˳�򣺰���key���������
//	map<T1, T2>::const_iterator it = m.begin();
//	while (it != m.end())
//	{
//		//����ֱ�����pair����
//		//cout<<it;
//		cout << it->first << "-->" << it->second << endl;
//		++it;
//	}
//}

//template <class T1, class T2>
//void printMap2(const map<T1, T2>& m)
//{
//	//map�е�������pair
//	//���������ʵ�˳�򣺰���key���������
//	map<T1, T2>::const_reverse_iterator it = m.rbegin();
//	while (it != m.rend())
//	{
//		//����ֱ�����pair����
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
//	//map��key�����ظ���value�����ظ�
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
//	//map�ĵ����������޸�value�������޸�key
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
//	//set������ظ����ݣ���Ȼȥ��
//	set<int> s2(arr, arr + sizeof(arr) / sizeof(arr[0]));
//
//	//set������������������Ȼ���򣺱��ʵ����������������
//	set<int>::iterator it = s2.begin();
//	while (it != s2.end())
//	{
//		//set��������֧���޸�
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
//	//insert������ʧ�ܣ��������ݵĵ�������false
//	pair<set<int>::iterator, bool> ret = s2.insert(10);
//	cout << ret.second << " "<< *ret.first << endl;
//	printSet(s2);
//	
//	//insert������ɹ��������ݵ�������true
//	ret = s2.insert(100);
//	cout << ret.second << " " << *ret.first << endl;
//	printSet(s2);
//
//	//iterator insert(iterator position,const value_type& val);
//	//insert(iterator,val):iteratorֻ��һ��λ�ý��飬�������ݵ�λ�ò�ָ����ָ��λ��֮ǰ
//	s2.insert(ret.first, 0);
//	printSet(s2);
//
//	//����һ�����������Ԫ��
//	int arr2[] = { 12,9,6,18,39,12,9,6};
//	s2.insert(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
//	printSet(s2);
//
//	int num = s2.erase(39);
//	printSet(s2);
//	cout << num << endl; //1,ɾ��һ��
//	num = s2.erase(39);
//	cout << num << endl;  //0��û�С�����ɾ��
//	s2.erase(s2.begin());
//	//erase:���ܴ��Ƿ�λ�ã�����end
//	//s2.erase(s2.end());
//	printSet(s2);
//
//	s2.erase(++s2.begin(), --s2.end()); //������һ�������һ��
//	printSet(s2);
//
//	auto iit = s2.find(1);
//	cout << (iit != s2.end()) << endl;//�ҵ�Ϊ1
//	iit = s2.find(10);
//	cout << (iit != s2.end()) << endl;//�Ҳ�������0
//
//	cout << s2.count(100) << endl; //�ҵ�����1
//	cout << s2.count(1000) << endl;//�Ҳ�������0
//}

int main()
{
	test();
	return 0;
}
