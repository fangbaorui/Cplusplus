#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

//void test()
//{
//	//cin:istream����
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
//	//cout:ostream����
//	cout << a << endl;
//	cout.operator<<(a).operator<<(endl);
//	cout << f << endl;
//	cout << arr << endl;
//
//	//sacnf,printf:�⺯����û������
//
//	cerr << f << endl;
//	clog << arr << endl;
//}


//void test()
//{
//	//ofstream:����ļ���
//	//ifstream:�����ļ���
//
//	ofstream fout("test.txt");
//	//fout.open("test.txt");
//	if (!fout.is_open())
//		cout << "file not open" << endl;
//
//	//д���ݣ��ļ������ڣ������ļ�
//	//1.�ı���ʽ���ַ�����д
//	fout << "test.txt" << endl;
//	fout.put(' ');
//	fout.put('a');
//	fout.close();
//
//	//���ļ����ļ������ڣ���ʧ��
//	ifstream fin("test.txt");
//	char arr[100];
//	//fin >> arr;
//
//	char ch;
//	ch = fin.get();
//	fin.get(ch);
//	//fin.get(arr, 100);//��100��
//	fin.getline(arr, 2);//��2��
//}

//struct Student
//{
//	char name[10];
//	int age;
//};
//void test()
//{   
//	//cout << sizeof(Student) << endl;
//	////�ı���ʽ
//	//ofstream fout("test.txt" );
//	//Student stu;
//	//stu.age = 30;
//	//strcpy(stu.name, "abc");
//	//fout << stu.name << endl;
//	//fout << stu.age << endl;
//	//fout.close();
//
//	////2.�����ƶ�д���ֽ�����д
//	////ofstream fout2("test.binary.txt",ofstream::binary);//����ָ��������д��Ҳ���Բ�д
//	//ofstream fout2("test.binary.txt");
//	//fout2.write((char*)&stu, sizeof(stu));
//	//fout2.close();
//
//	//ifstream fin("test.binary.txt",ifstream::binary);//����ָ�������ƶ���Ҳ���Բ�ָ��
//	ifstream fin("test.binary.txt");
//	Student stu;
//	/*fin >> stu.name;
//	fin >> stu.age;*/
//	fin.read((char*)&stu, sizeof(stu));
//}


void test()
{
	//atoi->�ַ���װ������  atof-> �ַ���ת�ɸ�����
	//itoa->����ת���ַ���
	int a = 10;  //ʮ����
	int b = 010;  //�˽���
	int c = 0x10;  //ʮ������
	char arr[100];
	itoa(a, arr, 10);  //ʮ����
	itoa(b, arr, 8);  //�˽���
	itoa(c, arr, 16);  //ʮ������

	//sprintf
	sprintf(arr, "%d", a);
	float f = 2.3;
	sprintf(arr, "%f", f);
	printf("%d", a);

	//1.��������ֵ-->�ַ���
	stringstream ss;
	string str;
	ss << a;
	ss >> str;
	//clear():��һ��ת��֮ǰ������clear�ӿ����״̬λ
	//clear():�������stringstream�����е�����
	ss.clear();
	ss << f;
	ss >> str;


	//str(��������):����stringstream�����е�����
	ss.str("");
	//str():��ȡstringstream�����е�����
	str = ss.str();

	ss.clear();
	ss << f;
	str = ss.str();

	//2.�������ַ���ƴ��
	ss.str("");
	ss << "123" << "456" << "789";
	cout << ss.str() << endl;
}

int main()
{
	test();
	return 0;
}