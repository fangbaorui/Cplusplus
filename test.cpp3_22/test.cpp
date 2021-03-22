#define _CRT_SECURE_NO_WARNINGS

////����д��
//#include<string>
//#include<iostream>
//using namespace std;
//class String
//{
//public:
//	//String()
//	//	:_data(new char[1])
//	//{
//	//	_data[0] = '\0';
//	//}
//
//	//ȫȱʡ���캯��
//	String(const char* str = "")
//		:_data(new char[strlen(str) + 1])
//	{
//		strcpy(_data, str);
//		cout << "String(char*)" << endl;
//	}
//
//
//	////ǳ����
//	//String(const String& str)
//	//	:_data(str._data)
//	//{}
//
//
//	String(const String& str)
//		:_data(new char[strlen(str._data) + 1])
//	{
//		//���
//		strcpy(_data, str._data);
//	}
//
//
//	const char* c_str() const
//	{
//		return _data;
//	}
//
//
//	String& operator=(const String& str)
//	{
//		if (this != &str)
//		{
//			//1.�ͷ�ԭ�еĿռ�
//			delete[] _data;
//			//2.�����µĿռ�
//			_data = new char[strlen(str._data) + 1];
//			//3.��������
//			strcpy(_data, str._data);
//		}
//		return *this;
//	}
//
//
//	~String()
//	{
//		if (_data)
//		{
//			delete[] _data;
//			_data = nullptr;
//			cout << "~String()" << endl;
//		}
//	}
//
//private:
//	char* _data;
//};
//
//
//void test()
//{
//	String str("123");
//	String copy(str);
//	String str2("456");
//	String str3;
//	str2 = str;
//	str3 = str2;
//
//	//��������
//	String str4 = str;
//}
//
//
////void test()
////{
////	String str("123");
////	//ǳ������ֻ������String���������
////	//String copy(str);   //ǳ����
////	String str2("456");
////	str2 = str;   //ǳ�������ڴ�й©
////};
//
//
////void test()
////{
////	String str;
////	cout << str.c_str() << endl;
////	String str2;
////	cout << str2.c_str() << endl;
////
////}
//
//int main()
//{
//	test();
//	return 0;
//}




//�ִ�д��
#include<string>
#include<iostream>
using namespace std;
class String
{
public:

	//ȫȱʡ���캯��
	String(const char* str = "")
		:_data(new char[strlen(str) + 1])
	{
		strcpy(_data, str);
		cout << "String(char*)" << endl;
	}


	//���������ִ�д��
	String(const String& str)
		:_data(nullptr)
	{
		String tmp(str._data);
		strcpy(tmp._data, _data);
	}


	const char* c_str() const
	{
		return _data;
	}


	//��ֵ��������ִ�д��
	//�ͷ�ԭ�пռ䣬�����µĿռ䣬��������
	String& operator=(String str)
	{
		swap(str._data, _data);
		return *this;
	}


	//String& operator=(const String& str)
	//{
	//	if (this != &str)
	//	{
	//		//1.�ͷ�ԭ�еĿռ�
	//		delete[] _data;
	//		//2.�����µĿռ�
	//		_data = new char[strlen(str._data) + 1];
	//		//3.��������
	//		strcpy(_data, str._data);
	//	}
	//	return *this;
	//}


	~String()
	{
		if (_data)
		{
			delete[] _data;
			_data = nullptr;
			cout << "~String()" << endl;
		}
	}

private:
	char* _data;
};


void test()
{
	String str("123");
	String copy(str);
}



int main()
{
	test();
	return 0;
}