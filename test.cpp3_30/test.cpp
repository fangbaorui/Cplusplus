#define _CRT_SECURE_NO_WARNINGS
#include<algorithm>
#include<list>
#include<iostream>
#include<assert.h>
using namespace std;
struct A
{
public:
	A(int a = 1)
		:_a(a)
	{
		cout << "A(int)" << endl;
	}
private:
	friend ostream& operator<<(ostream& out, const A& a);
	int _a;
};

ostream& operator<<(ostream& out, const A& a)
{
	out << a._a;
	return out;
}

template <class T>
class Vector
{
public:
	//���������ͣ�T*
	typedef T* iterator;
	typedef const T* const_iterator;

	Vector()
		:_start(nullptr)
		, _finish(nullptr)
		, _endofStorage(nullptr)
	{}

	Vector(size_t n, const T& val = T())
		:_start(new T())
		, _finish(_start + n)
		, _endofStorage(_start + n)
	{
		for (size_t i = 0; i < n; i++)
		{
			_start[i] = val;
		}
	}

	template<class InputIterator>
	Vector(InputIterator first, InputIterator last)
		:_start(nullptr)
		, _finish(nullptr)
		, _endofStorage(nullptr)
	{
		while (first != last)
		{
			pushback(*first);
			++first;
		}
	}

	void pushBack(const T& val)
	{
		//�������
		if (_finish == _endofStorage)
		{
			size_t newC = _endofStorage == nullptr ? 1 : 2 * capacity();
			reserve(newC);
		}
		//����
		*_finish = val;
		//����
		++_finish;
	}

	void reserve(size_t n)
	{
		if (n > capacity())
		{
			//����Ԫ�ظ���
			size_t sz = size();
			//����ռ�
			T* tmp = new T[n];
			//��������
			if��_start)
			{
			    //������ЧԪ��
				memcpy(tmp, _start, sizeof(T) * size());
				//�ͷ�ԭ�еĿռ�
				delete[] _start;
            }
			//����
			_start = tmp;
			//����д��
			//_finish = start + size();
			_finish = _start + sz;
			_endofStorage = _start + n;
		}
	}

	size_t size() const
	{
		return _finish - _start;
	}

	size_t capacity() const
	{
		return _endofStorage - _start;
	}

	iterator begin()
	{
		return _start;
	}

	iterator end()
	{
		return _finish;
	}

	const_iterator begin() const
	{
		return _start;
	}

	const_iterator end() const
	{
		return _finish;
	}

	T& operator[](size_t pos)
	{
		assert(pos < size());
		return _start[pos];
	}

	const T& operator[](size_t pos) const
	{
		assert(pos < size());
		return _start[pos];
	}

	void resize(size_t n, const T& val = T())
	{
		//n > capacity
		if (n > capacity())
		{
			reserve(n);
		}
		//size < n <= capacity
		if (n > size())
		{
			//[size,n):���val
			while (_finish != _start + n)
			{
				*_finish = val;
				++_finish;
			}
		}
		//n <= size
		_finish = _start + n;
	}

	void insert(iterator pos, const T& val)
	{
		//���λ��[_start,_finish]
		assert(pos >= _start && pos <= _finish);
		//�������
		if (_finish == _endofStorage)
		{
			//���ݻᵼ�µ�����ʧЧ
			//����pos��_start��ƫ����
			size_t offset = pos - _start;

			size_t newC = _endofStorage == nullptr ? 1 : 2 * capacity();
			reserve(newC);

			//����pos
			pos = _start + offset;
		}
		//�ƶ�Ԫ�أ��Ӻ���ǰ
		iterator end = _finish;
		while (end != pos)
		{
			*end = *(end - 1);
			--end;
		}
		//����
		*pos == val;
		//����
		++_finish;
	}

	void erase(iterator pos)
	{
		//��鷶Χ
		assert(pos >= _start && pos <= _finish);
		//Ԫ���ƶ�����ǰ����ƶ�
		iterator start = pos + 1;
		while (start != _finish)
		{
			//��һ��pos+1 --> pos
			//���һ��: _finish - 1 ---> _finish - 2
			*(start - 1) = *start;
			++start;
		}
		//����
		--_finish;
	}

	//βɾ
	void popBack()
	{
		if (size() > 0)
		{
			erase(end() - 1);
		}
	}

	~Vector()
	{
		if (_start)
		{
			delete[] _start;
			_start = _finish = _endofStorage = nullptr;
		}
	}

private:
	//_start:��һ��Ԫ�ص��׵�ַ
	iterator _start;
	//_finfish:���һ��Ԫ�صĽ�β
	iterator _finish;
	//_endofStorage:�ռ�Ľ�β
	iterator _endofStorage;
};


//����ģ��
template<class T>
void printVector(Vector<T>& vec,const T& val)
{
	Vector<T>::iterator it = vec.begin();
	while (it != vec.end())
	{
		cout << *it << " ";
		*it = val;
		++it;
	}
	cout << endl;
}

template<class T>
void printVector(const Vector<T>& vec)
{
	Vector<T>::const_iterator it = vec.begin();
	while (it != vec.end())
	{
		cout << *it << " ";
		//ֻ���������������޸�
		++it;
	}
	cout << endl;
}


template<class T>
void printVectorFor(Vector<T>& vec,const T& val)
{
	for (const auto& e : vec)
	{
		cout << e << " ";
		e = val;
	}
	cout << endl;
}

template<class T>
void printVectorFor(const Vector<T>& vec)
{
	for (const auto& e : vec)
	{
		cout << e << " ";
		//e = val;
	}
	cout << endl;
}

template <class T>
void printOperator(Vector<T>& vec, const T& val)
{
	for (size_t i = 0, i < vec.size(); i++)
	{
		cout << vec.operator[](i) << " ";
		vec[i] = val;
	}
	cout << endl;
}

template <class T>
void printOperator(const Vector<T>& vec)
{
	for (size_t i = 0, i < vec.size(); i++)
	{
		cout << vec.operator[](i) << " ";
	}
	cout << endl;
}


void test()
{
	Vector<int> v;
	v.pushBack(1);
	v.pushBack(2);
	v.pushBack(3);
	v.pushBack(4);
	v.pushBack(5);
	
	Vector<int>::iterator it = find(v.begin(), v.end(),3);
	if (it != v.end())
		cout << *it << endl;
	else
		cout << "not find" << endl;

	it = find(v.begin(), v.end(), 30);
	if (it != v.end())
		cout << *it << endl;
	else
		cout << "not find" << endl;
}
//void test()
//{
//	Vector<int> v;
//	v.pushBack(1);
//	v.pushBack(2);
//	v.pushBack(3);
//	v.pushBack(4);
//	v.pushBack(5);
//	printVector(v);
//	v.popBack();
//	printVector(v);
//	v.popBack();
//	printVector(v);
//	v.popBack();
//	printVector(v);
//	v.popBack();
//	printVector(v);
//	v.popBack();
//}

//void test()
//{
//	Vector<int> v;
//	Vector<int>::iterator it = v.begin();
//	v.insert(it, 2);
//	it = v.begin();
//	v.insert(it, 1);
//	cout << *it << endl;
//
//	v.pushBack(3);
//	v.pushBack(4);
//	v.pushBack(5);
//	v.pushBack(6);
//	it = v.begin();
//	v.erase(it);
//	it = v.end();
//	v.erase(--it);
//	it = v.begin();
//	v.erase(it + 1);
//}

//void test()
//{
//	Vector<A> v;
//	v.pushBack(A(1));
//	v.pushBack(A(2));
//	v.pushBack(A(3));
//	v.pushBack(A(4));
//	v.pushBack(A(5));
//	v.pushBack(A(6));
//
//	printVector(v,A(100));
//	printVector(v);
//
//	printVectorFor(v, A(200));
//	printVectorFor(v);
//
//	printOperator(v, A(300));
//}


//void test()
//{
//	string str = "1234567890";
//	//Vector<char> v(str.begin(), str.end());
//	list<char> lst(str.begin(), str.end());
//	Vector<char> v(lst.begin(), lst.end());
//	printVector(v, 'a');
//	printVector(v);
//}
//void test()
//{
//	Vector<int> v1(5);
//	Vector<char> v2(5);
//	Vector<int*> v3(5);
//	Vector<A> v4(5);
//
//	cout << v1.size() << endl;
//	cout << v2.size() << endl;
//	cout << v3.size() << endl;
//	cout << v4.size() << endl;
//	cout << v1.capacity() << endl;
//	cout << v2.capacity() << endl;
//	cout << v3.capacity() << endl;
//	cout << v4.capacity() << endl;
//}

int main()
{
	test();
	return 0;
}