#define _CRT_SECURE_NO_WARNINGS

#include<vector>
#include<iostream>
using namespace std;
//class A
//{};

//void test()
//{
//	vector<int> v1;
//	vector<char> v2;
//	vector<A> v3;
//
//	vector<A> v4(10);
//	A a;
//	//vector（n，自定义类型的默认构造（））
//	vector<A> v5(20, A());
//	vector<A> v6(20, a);
//
//	//vector（n，内置类型的类0值）
//	vector<int> v7(10);    //10个0
//	vector<char> v8(10);    //10个字符\0
//	vector<int*> v9(10);   // 10ge1指针空值：nullptr
//
//	char arr[] = "12345678";
//	vector<char> v10(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	//存放1 2 3 4 5 6 7 8 /0
//
//	//vector<char>::iterator it = v10.begin();
//	//while (it != v10.end())
//	//{
//	//	cout << *it << " ";
//	//	++it;
//	//}
//	//cout << endl;
//
//	//it = v10.begin();
//	//while (it != v10.end())
//	//{
//	//	cout << *it << " ";
//	//	*it = 'a';
//	//	++it;
//	//}
//	//cout << endl;
//
//	vector<char>::reverse_iterator it = v10.rbegin();
//	while (it != v10.rend())
//	{
//		cout << *it << " ";
//		*it = 'a';
//		++it;
//	}
//	cout << endl;
//
//}

template<class T>
void printIterator(const vector<T>& vec)
{
	vector<T>::const_iterator it = vec.begin();
	while (ir != vec.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

template<class T>
void printReverseIterator(const vector<T>& vec)
{
	vector<T>::const_reverse_iterator it = vec.rbegin();
	while (ir != vec.rend())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

template<class T>
void printFor(const vector<T>& vec)
{
	for (const auto& e : vec)
	{
		cout << e << " ";
	}
	cout << endl;
}

template<class T>
void printFor2(const vector<T>& vec)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}


//void test()
//{
//	vector<int> v7(10);    
//	vector<char> v8(10);   
//	vector<int*> v9(10);
//	char arr[] = "12345678";
//	vector<char> v10(arr, arr + sizeof(arr) / sizeof(arr[0]));
//
//	printIterator(v7);
//	printIterator(v8);
//	printIterator(v9);
//	printIterator(v10);
//
//	printReverseIterator(v10);
//
//	for (auto& ch : v8)
//	{
//		ch = '1';
//	}
//
//	printFor(v8);
//	printFor(v10);
//	printFor(v8);
//
//	for (size_t i = 0; i < v10.size(); ++i)
//	{
//		v10.operator[](i) = 'a';
//		v10[i] = 'b';
//	}
//
//	printFor2(v10);
//
//	//[]越界：debug版本assert错误，release版本不会检查错误
//	//v10[100] = 'c';
//	//v10.at(100);  // at越界：抛异常
//}



//struct A
//{
//	int _a;
//	int _b;
//	char _c;
//	char* _ptr;
//};
//void test()
//{
//	vector<char> v1;
//	vector<char*> v2;
//	vector<int> v3;
//	vector<A> v4;
//	cout << v1.max_size() << endl;
//	cout << v2.max_size() << endl;
//	cout << v3.max_size() << endl;
//	cout << v4.max_size() << endl;
//
//	//void resize(size_type n,value_type val=value_type())
//	printFor(v1);
//	v1.resize(10);
//	printFor(v1);
//	v4.resize(10);
//	
//	v1.resize(5, 'a');
//	//resize(n,T())  n大于容量：影响容量
//	v1.resize(100, 'b');
//}

//void test()
//{
//	vector<int> v;
//	//v.reserve(200);
//	//PJ中vector增容规则：1.5倍
//	size_t cap = v.capacity();
//	cout << cap << endl;
//	for (int i = 0; i < 200; i++)
//	{
//		v.push_back(i);
//		if (cap != v.capacity())
//		{
//			cap = v.capacity();
//			cout << cap << endl;
//		}
//	}
//}


//void test()
//{
//	vector<int> v;
//	cout << v.size() << endl;  //0
//	cout << v.capacity() << endl;  //0
//
//	v.resize(10);
//	v.reserve(30);
//	v.shrink_to_fit();
//	cout << v.size() << endl;  //10
//	cout << v.capacity() << endl;  //10
//
//	v.reserve(1000);
//	v.shrink_to_fit();
//	cout << v.size() << endl;   //10
//	cout << v.capacity() << endl;   //10
//}

//void test()
//{
//	vector<int> v(3, 2);  //2 2 2
//	//赋值
//	v.assign(5, 1);  //1 1 1 1 1
//	vector<int> v2(3, 6);  //6 6 6
//	v.assign(v2.begin(), v2.end());  
//
//	int arr[] = { 1,2,3,4 };
//	v.assign(arr, arr + sizeof(arr) / sizeof(arr[0]));  //1 2 3 4
//	printFor(v);
//	v.pop_back(); //1 2 3
//	printFor(v);
//	v.pop_back();  // 1 2
//	printFor(v);
//	v.pop_back(); //1
//	printFor(v);
//	v.pop_back();
//
//	v.insert(v.begin(), 0);  //0
//	printFor(v);
//	v.insert(v.end(), 10);  //0 10
//	printFor(v);
//	v.insert(++v.begin(), 1);  //0 1 10
//	printFor(v);
//	v.insert(--v.end(), v2.begin(), v2.end());  //0 1 6 6 6 10
//	printFor(v);
//	v.insert(v.begin(), 3, -1); //-1 -1 -1 0 1 6 6 6 10
//	printFor(v);
//
//	v.erase(v.begin());  //-1 -1 0 1 6 6 6 10
//	printFor(v);
//	v.erase(++v.begin(), --v.end());  // -1 10
//	printFor(v);
//}


//struct A
//{
//	A(int a,int b,char c)
//		:_a(a)
//		,_b(b)
//		,_c(c)
//		,_ptr(nullptr)
//	{}
//	int _a;
//	int _b;
//	char _c;
//	char* _ptr;
//};
//void test()
//{
//	vector<A> v2;
//	A a1(1, 1, 1);
//	v2.insert(v2.begin(), a1);
//	v2.emplace(v2.begin(), a1);
//
//	v2.emplace(v2.end(), 2, 2, 2);
//
//	vector<A> v3;
//	v3.swap(v2);
//	swap(v3, v2);
//	v2.clear();  //值清空size,capacity不变
//}

void test()
{
	vector<int> v(3, 0);
	vector<int>::iterator it = v.begin();
	cout << *it << endl;
	//迭代器失效：
	//1.迭代器指向的位置无效：空间释放（非法访问）
	//2.指向发生了变化（错位）
	//空间发生变化或删除，都会引起迭代器失效
	//v.resize(30,1);
	//v.reserve(30);
	//v.insert(v.begin(),1);
	//v.push_back(2);
	//v.emplace(v.begin(), 3);
	it = v.erase(it);
	//解决方式：重新获取迭代器
	//it=v.begin();

	//it=v.erase(--v.end());
	cout << *it << endl;
}


int main()
{
	test();
	return 0;
}