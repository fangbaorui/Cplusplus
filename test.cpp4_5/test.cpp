#define _CRT_SECURE_NO_WARNINGS
#include<list>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

void test()
{
	list<int> lst;
	list<char> lst2;

	list<int> lst3(3, 5);   //5 5 5
	string str = "123456";
	list<char> lst4(str.begin(), str.end());
	char arr[] = "abcdg";
	list<char> lst5(arr, arr + sizeof(arr) / sizeof(arr[0]));

	vector<char> v(str.begin(), str.end());
	list<char> lst6(v.begin(), v.end());
}

void test()
{
	string s = "12345";
	list<char> lst(s.begin(), s.end());

	cout << "���������" << endl;
	list<char>::iterator it = lst.begin();
	while (it != lst.end())
	{
		cout << *it << " ";
		*it = 'a';
		++it;
	}
	cout << endl;

	list<char>::const_iterator cit = lst.cbegin();
	while (cit != lst.cend())
	{
		cout << *cit << " ";
		//ֻ��������
		++cit;
	}
	cout << endl;

	cout << "���������" << endl;
	list<char> lst2(s.rbegin(), s.rend());
	list<char>::reverse_iterator rit = lst2.rbegin();
	while (rit != lst2.rend())
	{
		cout << *rit << " ";
		*rit = 'c';
		++rit;
	}
	cout << endl;

	//���������������
	cout << "����������������" << endl;
	list<char> lst3(s.begin(), s.end());
	list<char>::const_reverse_iterator crit = lst3.crend();
	--crit;
	while (crit != lst3.crbegin())
	{
		cout << *crit << " ";
		--crit;
	}
	cout << *crit << endl;

	//��Χfor
	for (auto& e : lst3)
	{
		cout << e << " ";
		e = 'c';
	}
	cout << endl;

	for (const auto& e : lst3)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test()
{
	list<int> lst;
	lst.push_front(1);  //1
	lst.push_back(2);   //12
	lst.insert(lst.begin(), 0);  //0 1 2

	list<int>::iterator it = lst.begin();
	cout << *it << endl;

	lst.insert(lst.end(), 3);  // 0 1 2 3
	lst.emplace(lst.begin(), -1);  //-1 0 1 2 3
	lst.emplace_back(4);  //-1 0 1 2 3 4
	lst.emplace_front(-2);  //-2 -1 0 1 2 3 4

	list<int> copy = lst;
	lst.insert(lst.end(), copy.begin(), copy.end());  ////-2 -1 0 1 2 3 4 -2 -1 0 1 2 3 4
	for (const auto& e : lst)
	{
		cout << e << " ";
	}
	cout << endl;

	//���벻�ᵼ�µ�����ʧЧ
	cout << *it << endl;

	//ɾ���ᵼ�µ�����ʧЧ
	//erase����ֵ��������-> ��ɾ��Ԫ�ص���һ��λ��
	it = lst.erase(it);
	cout << *it << endl;

	cout << lst.size() << endl;
	//lst.clear();
	//cout<<lst.size()<<endl;
	lst.resize(5, 100);
	for (const auto& e : lst)
	{
		cout << e << " ";
	}
	cout << endl;

	lst.resize(7, 200);
}

bool compareList(const int& a, const int& b)
{
	return a > b;
}
template <class T>
void printList(const list<T>& lst)
{
	for (const auto& e : lst)
		cout << e << " ";
	cout << endl;
}
void test()
{
	string s = "123";
	string s2 = "abc";
	list<char> lst(s.begin(), s.end());
	list<char> lst2(s2.begin(), s2.end());
	//splice�ַ���ƴ�ӣ���ƴ�ӵ����ַ���û����
	//lst.splice(lst.begin(), lst2);
	//printList(lst);   //a b c 1 2 3
	//printList(lst2);  //ʲô��û����

	//lst.splice(lst.begin(),lst2, ++lst2.begin());
	//printList(lst);   // b  1 2 3
	//printList(lst2);  //a c

	lst.splice(lst.begin(), lst2,++lst2.begin(),lst2.end());
	printList(lst);   //b c 1 2 3
	printList(lst2);  //a

	lst.remove('f');  //removeɾ��һ��ָ����Ԫ�أ����û�����Ԫ�ؾͲ�ɾ��
	printList(lst);  //b c 1 2 3

	lst.push_back('1');
	lst.push_back('2');
	lst.push_back('3');
	lst.push_back('a');
	lst.push_back('b');
	printList(lst);   // b c 1 2 3 1 2 3 a b
	//unique:���������������£�����Ԫ�ص�ȥ��
	lst.unique();    // b c 1 2 3 1 2 3 a b
	printList(lst);
	lst.sort();      //1 1 2 2 3 3 a b b c
	printList(lst);
	lst.unique();   // 1 2 3 a b c
	printList(lst);

	lst.sort(compareList);
	printList(lst);   //c b a 3 2 1
}

void test()
{
	int arr[] = { 10,3,2,9 };
	int arr2[] = { 10,13,21,29 };
	list<int> lst(arr, arr + 4);
	list<int> lst2(arr2, arr2 + 4);
	lst.sort();
	lst2.sort();
	lst.merge(lst2);
	printList(lst);// 2 3 9 10 10 13 21 29
}

int main()
{
	test();
	return 0;
}