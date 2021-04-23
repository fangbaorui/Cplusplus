#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

//void test()
//{
//	//cin:istream对象
//	int a;
//	cin >> a;
//	//cin.operator>>(a);
//	float f;
//	cin >> f;
//	//cin.operator>>(f);
//
//	char arr[10];
//	cin >> arr;
//	
//	//cout:ostream对象
//	cout << a << endl;
//	cout.operator<<(a).operator<<(endl);
//	cout << f << endl;
//	cout << arr << endl;
//
//	//sacnf,printf:库函数，没有重载
//
//	cerr << f << endl;
//	clog << arr << endl;
//}


//void test()
//{
//	//ofstream:输出文件流
//	//ifstream:输入文件流
//
//	ofstream fout("test.txt");
//	//fout.open("test.txt");
//	if (!fout.is_open())
//		cout << "file not open" << endl;
//
//	//写内容：文件不存在，创建文件
//	//1.文本形式：字符流读写
//	fout << "test.txt" << endl;
//	fout.put(' ');
//	fout.put('a');
//	fout.close();
//
//	//读文件：文件不存在，打开失败
//	ifstream fin("test.txt");
//	char arr[100];
//	//fin >> arr;
//
//	char ch;
//	ch = fin.get();
//	fin.get(ch);
//	//fin.get(arr, 100);//读100个
//	fin.getline(arr, 2);//读2个
//}

//struct Student
//{
//	char name[10];
//	int age;
//};
//void test()
//{   
//	//cout << sizeof(Student) << endl;
//	////文本形式
//	//ofstream fout("test.txt" );
//	//Student stu;
//	//stu.age = 30;
//	//strcpy(stu.name, "abc");
//	//fout << stu.name << endl;
//	//fout << stu.age << endl;
//	//fout.close();
//
//	////2.二进制读写：字节流读写
//	////ofstream fout2("test.binary.txt",ofstream::binary);//可以指定二进制写，也可以不写
//	//ofstream fout2("test.binary.txt");
//	//fout2.write((char*)&stu, sizeof(stu));
//	//fout2.close();
//
//	//ifstream fin("test.binary.txt",ifstream::binary);//可以指定二进制读，也可以不指定
//	ifstream fin("test.binary.txt");
//	Student stu;
//	/*fin >> stu.name;
//	fin >> stu.age;*/
//	fin.read((char*)&stu, sizeof(stu));
//}


void test()
{
	//atoi->字符串装成整数  atof-> 字符串转成浮点数
	//itoa->整数转成字符串
	int a = 10;  //十进制
	int b = 010;  //八进制
	int c = 0x10;  //十六进制
	char arr[100];
	itoa(a, arr, 10);  //十进制
	itoa(b, arr, 8);  //八进制
	itoa(c, arr, 16);  //十六进制

	//sprintf
	sprintf(arr, "%d", a);
	float f = 2.3;
	sprintf(arr, "%f", f);
	printf("%d", a);

	//1.场景：数值-->字符串
	stringstream ss;
	string str;
	ss << a;
	ss >> str;
	//clear():下一次转换之前，调用clear接口清空状态位
	//clear():不会清空stringstream对象中的内容
	ss.clear();
	ss << f;
	ss >> str;


	//str(重置内容):重置stringstream对象中的内容
	ss.str("");
	//str():获取stringstream对象中的内容
	str = ss.str();

	ss.clear();
	ss << f;
	str = ss.str();

	//2.场景：字符串拼接
	ss.str("");
	ss << "123" << "456" << "789";
	cout << ss.str() << endl;
}

int main()
{
	test();
	return 0;
}