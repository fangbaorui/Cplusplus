#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
void test()
{
	string str;
	string str2 = "123";
	str += str2;   //123
	str += "abc";   //123abc
	str += '4';   //123abc4
	str.operator+=('5');   //123abc45
}



void test()
{
	string str;
	string str2 = "123";
	//*string(1):string& append(const string& str);
	str.append(str2);  //123
	//*substring(2):
	//string& append(const string& str, size_t subpos, size_t sublen);
	str.append(str2, 1, 1);  //1232
	//*c-string(3):string& append(const char* s);
	str.append("abc");  //1232abc
	//*buffer(4):string& append(const char* s, size_t n);
	str.append("123456", 6);  //1232abc123456
	//*fill(5):string& append(size_t n,char c);
	str.append(5, 'm');  //1232abc123456mmmmm
	//*range(6):template<class InputIterator>
	//string& append(InputIterator first,InputIterator last);
	char arr[] = "abcdefg";
	str.append(arr, arr + sizeof(arr) / sizeof(arr[0])); 
	//1232abc123456mmmmmabcdefg
	str.append(str2.begin(), str2.end());
	//1232abc123456mmmmmabcdefg\0123
}



void test()
{
	//string(1):string& assign(const string& str);
	//substring(2):string& assign(const string& str,size_t subpos,size_t sublen);
	//c-string(3):string& assign(const char* s);
	//buffer(4):string& assign(const char* s,size_t n);
	//fill(5):string& assign(size_t n,char c);
	//rang(6):template<class InputIterator>
	//string& assign(InputIterator first,InputIterator last);

	//赋值：assign
	string str;
	string str2 = "123";
	str.assign(str2);  //123
	str.assign(str2, 1, 1);  //2
	str.assign("abc");  //abc
	str.assign("abcde", 2);  //ab
	str.assign(5, 'a');  //aaaaa
	str.assign(++str2.begin(), str2.end());  //23
}


void test()
{
	//insert：插入
	//string(1):string& insert(size_t pos,const string& str);
	string str = "123";  //123
	string str2 = "abc";
	str.insert(0, str2);  //abc123
	//substring(2):
	//string& insert(size_t pos,const string& str,size_t subpos,size_t sublen);
	str.insert(4, str2, 1, 2);  //abc1bc23
	//c-string(3):string& insert(size_t pos,const char* s);
	str.insert(str.size(), "abc");  //abc1bc23abc
	//buffer(4):string& insert(size_t pos,const char* s,size_t n);
	str.insert(5, "12345", 4);  //abc1b 1234 c23abc
	//fill(5):string& insert(size_t pos,size_t n,char c);
	//void insert(iterator p,size_t n,char c);
	str.insert(str.begin(), 2, '0'); //00 abc1b1234c23abc
	//single character(6):iterator insert(iterator p,char c);

	//range(7):template<class InputIterator>
	//void insert(iterator p,InputIterator first,InputIterator last);
	str.insert(str.end(), str2.begin(), str2.end()); //00 abc1b1234c23abc123
}



void test()
{
	//正向查找
	string str = "1234567890123456123";
	string str2 = "123";
	//find：第一次遇到匹配的位置，则查找结束
	size_t pos = str.find("123");  //0
	pos = str.find(str2); //0
	pos = str.find("ab");  //4G,没找到

	//字符串"45"出现的位置
	pos = str.find("456abc", 0, 2);  //3

	//字符串"456"出现的位置
	pos = str.find("456abc", 0, 3);  //3

	//字符串"456a"出现的位置
	pos = str.find("456abc", 0, 4);  //4G
}


void test()
{
	//反向查找
	string str = "1234567890123456123";
	string str2 = "123";
	size_t pos = str.rfind(str2);
	
	string str3 = "http://www.cplusplus.com/reference/String/string/substring";
	pos = str3.find("://");
	size_t end = str3.find("/", pos + 3);
	string sub = str3.substr(pos + 3, end - pos - 3);

	string file = "test.tar.gz.txt";
	pos = file.rfind('.');
	string suffix = file.substr(pos + 1);

	//find_first_of(str):找到str中任意一个字符第一次出现的位置
	pos = str.find_first_of("a23bcd", 0);  //1
	//find_last_of(str):找到str中任意一个字符最后一次出现的位置
	pos = str.find_last_of("a23bcd", 0);  //18


	//find_first_not_of(str):找到不属于str中任意一个字符第一次出现的位置
	pos = str.find_first_not_of("1a23bcd", 0);  //3
	//find_last_not_of(str):找到不属于str中任意一个字符最后一次出现的位置
	pos = str.find_first_not_of("1a23bcd", 0);  //15
}


void test()
{
	//string的比较：按照每个字符的ASCII码值进行比较
	string str = "123445";
	string str2 = "ab";
	bool ret = str == str2;  //false
	ret = str > str2;   //false
	ret = str2 > str;   //ture

	cout << str << endl;
	//输入cin：遇到空格/换行结束
	cin >> str2;
	//getline：遇到换行结束
	getline(cin, str2);
	//istream& getline(istream& is,string& str,char delim);
	//遇到delim结束
	getline(cin, str2, ',');
}


