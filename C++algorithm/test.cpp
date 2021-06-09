
#include <numeric>
#include <vector>
#include <algorithm>
#include<iostream>
#include<list>
#include<functional>
using namespace std;

//next_permutation递增序列的排列组合
//prev_permutation递减序列的排列组合
void test()
{
	// 因为next_permutation函数是按照大于字典序获取下一个排列组合的
	// 因此在排序时必须保证序列是升序的
	vector<int> v = { 4, 1, 2, 3 };
	sort(v.begin(), v.end());//1 2 3 4
	do
	{
		cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << endl;
	} while (next_permutation(v.begin(), v.end()));
	cout << endl;
	// 因为prev_permutation函数是按照小于字典序获取下一个排列组合的
	// 因此在排序时必须保证序列是降序的
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
//	//去重,覆盖,不会真正删除数据
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
//		cout << *iter<< " ";//多余的元素还在，没打印
//	}
//	cout << endl;
//
//	v1.erase(it, v1.end());//删除多余的元素
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
//	//按奇数划分，划分返回值是最后一个奇数的下一个位置
//	partition(v1.begin(), v1.end(), isOdd);
//	for (const auto& e : v1)
//	{
//		cout << e << " "; 
//	}
//}


////partial_sort走的是堆结构
//void test()
//{
//	vector<int> v1 = { 12,13,1,5,9,23,16 };
//	//只能保证前4个有序
//	partial_sort(v1.begin(), v1.begin() + 4, v1.end());
//	for (const auto& e : v1)
//	{
//		cout << e << " ";  //1,5,9,12,.....
//	}
//	cout << endl;
//	//全部有序
//	partial_sort(v1.begin(), v1.begin() + 4, v1.end());
//
//	//前4个递减
//	partial_sort(v1.begin(), v1.begin() + 4, v1.end(),greater<int>());
//}




//void test()
//{
//	vector<int> v1 = { 1,2,3 };
//	list<int> v2 = { 4,5,6 };
//	vector<int> v3(v1.size() + v2.size());
//
//	//元素区间要有序
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
//	// 统计10在v1中出现的次数
//	vector<int> v1{ 10, 20, 30, 30, 20, 10, 10, 20 };
//	cout << count(v1.begin(), v1.end(), 10) << endl;
//	// 统计v2中有多少个偶数
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
//	// 对区间中的元素进行累加
//	vector<int> v{ 10, 20, 30 };
//	cout << accumulate(v.begin(), v.end(), 0) << endl;
//	// 对区间中的每个元素乘2，然后累加
//	cout << accumulate(v.begin(), v.end(), 0, Mul2()) << endl;
//	return 0;
//}





