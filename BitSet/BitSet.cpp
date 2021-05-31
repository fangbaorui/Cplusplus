#include<iostream>
#include<vector>
using namespace std;

//��¡������
class BitSet
{
public:
	//λͼ���ڴ��С�����ݷ�Χ�й�
	BitSet(size_t range)
		:_bit(range / 32 + 1)
	{}

	//�洢��Ϣ
	void set(size_t num)
	{
		//����λ��
		//1.��������λ�ã�/32
		int idx = num / 32;
		//2.����bitλ�ã�%32
		int bitIdx = num % 32;
		//�Ѷ�Ӧ��bitλ��1
		//��λ������
		_bit[idx] |= 1 << bitIdx;
	}

	//������Ϣ
	bool test(size_t num)
	{
		int idx = num / 32;
		int bitIdx = num % 32;
		return (_bit[idx] >> bitIdx) & 1;
	}

	//ɾ����Ϣ
	void reset(size_t num)
	{
		int idx = num / 32;
		int bitIdx = num % 32;
		_bit[idx] &= ~(1 << bitIdx);
	}

private:
	//��������
	vector<int> _bit;
};

//m:��Ҫ��bitλ�Ĵ�С
//n:Ԫ�ظ���
//k:��ϣ��������
//k = m / n * ln2    m = k * n * 1.4
// 
//ʹ�ó�������Ÿ������ݵļ���Ϣ
// �������������жϴ��ڣ������һ����ȷ
// һ��û��ɾ��������������ɾ
//ʱ�临�Ӷȣ�0��k��-->��ϣ�����ĸ���

template <class T,class Hash1,class Hash2,class Hash3>
class BloomFilter
{
public:
	BloomFilter(size_t num)
		:_bit(5 * num)
		,bitCount(5 * num)
	{}

	//�洢��Ϣ��ʹ�ö��bitλ�洢��Ϣ
	void set(const T& val)
	{
		Hash1 h1;
		Hash2 h2;
		Hash3 h3;
		int idx1 = h1(val) % bitCount;
		int idx2 = h2(val) % bitCount;
		int idx3 = h3(val) % bitCount;
		_bit.set(idx1);
		_bit.set(idx2);
		_bit.set(idx3);
	}

	bool test(const T& val)
	{
		Hash1 h1;
		Hash2 h2;
		Hash3 h3;
		int idx1 = h1(val) % bitCount;
		int idx2 = h2(val) % bitCount;
		int idx3 = h3(val) % bitCount;

		if (!_bit.test(idx1))
			return false;
		if (!_bit.test(idx2))
			return false;
		if (!_bit.test(idx3))
			return false;

		return true; //���ܴ���
	}

private:
	BitSet _bit;
	//bitλ�ĸ���
	size_t bitCount;
};

struct HashFun1
{
	size_t operator()(const string& str)
	{
		size_t hash = 0;
		for (const auto& ch : str)
		{
			hash = hash * 131 + ch;
		}
		return hash;
	}
};

struct HashFun2
{
	size_t operator()(const string& str)
	{
		size_t hash = 0;
		for (const auto& ch : str)
		{
			hash = hash * 65599 + ch;
		}
		return hash;
	}
};

struct HashFun3
{
	size_t operator()(const string& str)
	{
		size_t hash = 0;
		for (const auto& ch : str)
		{
			hash = hash * 1313131 + ch;
		}
		return hash;
	}
};

void test()
{
	BloomFilter<string, HashFun1, HashFun2, HashFun3> bf(10);
	string str1 = "https://free.lanzoux.com/b0cpu1guf1";
	string str2 = "https://free.lanzoux.com/b0cpu1guf2";
	string str3 = "https://free.lanzoux.com/b0cpu1guf3";
	string str4 = "https://free.lanzoux.com/b0cpu1guf4";

	bf.set(str1);
	bf.set(str2);
	bf.set(str3);

	bool ret = bf.test(str1);
	ret = bf.test(str2);
	ret = bf.test(str3);
	ret = bf.test(str4);

}

int main()
{
	test();
	return 0;
}





////λͼ:ʹ�ó���---����Ų��ظ����ݵļ���Ϣ������Ҫ������ݱ���
////�ŵ㣺��ʡ�ռ䣬����Ч�ʸ�o��1��
//class BitSet
//{
//public:
//	//λͼ���ڴ��С�����ݷ�Χ�й�
//	BitSet(size_t range)
//		:_bit(range / 32 + 1)
//	{}
//
//	//�洢��Ϣ
//	void set(size_t num)
//	{
//		//����λ��
//		//1.��������λ�ã�/32
//		int idx = num / 32;
//		//2.����bitλ�ã�%32
//		int bitIdx = num % 32;
//		//�Ѷ�Ӧ��bitλ��1
//		//��λ������
//		_bit[idx] |= 1 << bitIdx;
//	}
//
//	//������Ϣ
//	bool test(size_t num)
//	{
//		int idx = num / 32;
//		int bitIdx = num % 32;
//		return (_bit[idx] >> bitIdx) & 1;
//	}
//
//	//ɾ����Ϣ
//	void reset(size_t num)
//	{
//		int idx = num / 32;
//		int bitIdx = num % 32;
//		_bit[idx] &= ~(1 << bitIdx);
//	}
//
//private:
//	//��������
//	vector<int> _bit;
//};
//
//void test()
//{
//	BitSet bit(512);
//	bit.set(1);
//	bit.set(512);
//	bit.set(32);
//	bit.set(64);
//	bit.set(15);
//	bit.reset(15);
//	bit.set(47);
//	bit.reset(47);
//
//	bool ret = bit.test(1);
//	ret = bit.test(47);
//	ret = bit.test(100);
//}
//
//int main()
//{
//	test();
//	return 0;
//}