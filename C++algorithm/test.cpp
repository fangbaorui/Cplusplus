
#include <numeric>
#include <vector>
#include <algorithm>
#include<iostream>
#include<list>
#include<functional>
using namespace std;

//next_permutation�������е��������
//prev_permutation�ݼ����е��������
void test()
{
	// ��Ϊnext_permutation�����ǰ��մ����ֵ����ȡ��һ��������ϵ�
	// ���������ʱ���뱣֤�����������
	vector<int> v = { 4, 1, 2, 3 };
	sort(v.begin(), v.end());//1 2 3 4
	do
	{
		cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << endl;
	} while (next_permutation(v.begin(), v.end()));
	cout << endl;
	// ��Ϊprev_permutation�����ǰ���С���ֵ����ȡ��һ��������ϵ�
	// ���������ʱ���뱣֤�����ǽ����
	sort(v.begin(), v.end());
	sort(v.begin(), v.end(), greater<int>());
	do
	{
		cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << endl;
	} while (prev_permutation(v.begin(), v.end()));
}



//bool isOdd(int a)
//{
//	return a % 2 == 1;
//}
//void test()
//{
//	vector<int> v1 = { 12,12,13,1,5,9,12,23,16,23};
//	sort(v1.begin(), v1.end());
//	//ȥ��,����,��������ɾ������
//	/*unique(v1.begin(), v1.end());
//	for (const auto& e : v1)
//	{
//		cout << e << " "; 
//	}
//	cout << endl;*/
//
//	auto it = unique(v1.begin(), v1.end());
//	for (auto iter = v1.begin(); iter != it; ++iter)
//	{
//		cout << *iter<< " ";//�����Ԫ�ػ��ڣ�û��ӡ
//	}
//	cout << endl;
//
//	v1.erase(it, v1.end());//ɾ�������Ԫ��
//	for (auto& e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}




//bool isOdd(int a)
//{
//	return a % 2 == 1;
//}
//void test()
//{
//	vector<int> v1 = { 12,13,1,5,9,23,16 };
//	//���������֣����ַ���ֵ�����һ����������һ��λ��
//	partition(v1.begin(), v1.end(), isOdd);
//	for (const auto& e : v1)
//	{
//		cout << e << " "; 
//	}
//}


////partial_sort�ߵ��Ƕѽṹ
//void test()
//{
//	vector<int> v1 = { 12,13,1,5,9,23,16 };
//	//ֻ�ܱ�֤ǰ4������
//	partial_sort(v1.begin(), v1.begin() + 4, v1.end());
//	for (const auto& e : v1)
//	{
//		cout << e << " ";  //1,5,9,12,.....
//	}
//	cout << endl;
//	//ȫ������
//	partial_sort(v1.begin(), v1.begin() + 4, v1.end());
//
//	//ǰ4���ݼ�
//	partial_sort(v1.begin(), v1.begin() + 4, v1.end(),greater<int>());
//}




//void test()
//{
//	vector<int> v1 = { 1,2,3 };
//	list<int> v2 = { 4,5,6 };
//	vector<int> v3(v1.size() + v2.size());
//
//	//Ԫ������Ҫ����
//	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
//	for (auto& e : v3)
//		cout << e << " ";
//	cout << endl;
//}
int main()
{
	test();
	return 0;
}






//#include <algorithm>
//#include <vector>
//bool IsOdd(int i)
//{
//	return ((i % 2) == 1);
//}
//struct IsO
//{
//	bool operator()(int i)
//	{
//		return i % 2 == 0;
//	}
//};
//int main()
//{
//	// ͳ��10��v1�г��ֵĴ���
//	vector<int> v1{ 10, 20, 30, 30, 20, 10, 10, 20 };
//	cout << count(v1.begin(), v1.end(), 10) << endl;
//	// ͳ��v2���ж��ٸ�ż��
//	vector<int> v2{ 0,1,2,3,4,5,6,7,9 };
//	cout << count_if(v2.begin(), v2.end(), IsOdd) << endl;
//
//	cout << count_if(v2.begin(), v2.end(), IsO()) << endl;
//	
//	vector<int>::iterator it = find(v1.begin(), v1.end(), 30);
//	if (it != v1.end())
//		cout << *it << endl;
//	it = find(v1.begin(), v1.end(), 100);
//	if (it != v1.end())
//		cout << *it << endl;
//	else
//		cout << "not find" << endl;
//
//	/*it = find(v2.begin(), v2.end(), IsOdd);
//	cout << *it << endl;
//	it = find(v2.begin(), v2.end(), IsO());
//	cout << *it << endl;*/
//	return 0;
//}





//#include <numeric>
//struct Mul2
//{
//	int operator()(int x, int y) { return x + 2 * y; }
//};
//int main()
//{
//	// �������е�Ԫ�ؽ����ۼ�
//	vector<int> v{ 10, 20, 30 };
//	cout << accumulate(v.begin(), v.end(), 0) << endl;
//	// �������е�ÿ��Ԫ�س�2��Ȼ���ۼ�
//	cout << accumulate(v.begin(), v.end(), 0, Mul2()) << endl;
//	return 0;
//}





