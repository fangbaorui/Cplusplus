#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "FileCompress.h"
#include <queue>
#include <functional>
#include "HuffmanTree.hpp"

void TestPriorityQueue1()
{
	// Ĭ���ǰ���С�ڷ�ʽ�Ƚ�--->���
	// ֻ�轫���е�Ԫ�ذ��մ��ڷ�ʽ�Ƚ�--->С��
	priority_queue<int> q;
	q.push(4);
	q.push(1);
	q.push(6);
	q.push(5);
	q.push(2);
}



void TestPriorityQueue2()
{
	// Ĭ���ǰ���С�ڷ�ʽ�Ƚ�--->���
	// ֻ�轫���е�Ԫ�ذ��մ��ڷ�ʽ�Ƚ�--->С��
	priority_queue<int, vector<int>, greater<int>> q;
	q.push(4);
	q.push(1);
	q.push(6);
	q.push(5);
	q.push(2);
}


int main()
{
	//TestPriorityQueue2();
	//TestHuffmanTree();

	FileCompress fc;
	fc.CompressFile("1.txt");
	fc.UNCompressFile("2.txt");
	return 0;
}
