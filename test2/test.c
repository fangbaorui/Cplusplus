
#include<stdio.h>
////编写一个函数实现n的k次方，使用递归实现。
//int Pow(int n, int k)
//{
//	if (k == 1)
//		return n;
//	else
//		return n * Pow(n, k - 1);
//}


////计算一个数的每位之和（递归实现）
//int DigitSum(int n)
//{
//	if (n > 9)
//		return n % 10 + DigitSum(n / 10);
//	else
//		return n;
//}


////字符串逆序
//char* reverse_string(char* str)
//{
//	char* left = str;
//	char* right = str + strlen(str) - 1;
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//
//		left++;
//		right--;
//	}
//}


////实现一个对整形数组的冒泡排序
//void BubbleSort(int array[], int n)
//{
//	for (int i = 0; i < n - 1; i++)
//	{
//		for (int j = 1; j < n - i; j++)
//		{
//			if (array[j - 1] > array[j])
//			{
//				int tmp = array[j - 1];
//				array[j - 1] = array[j];
//				array[j] = tmp;
//			}
//		}
//	}
//}


//void Init(int arr[], int sz, int set)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		arr[i] = set;
//	}
//}
//
//void Print(int arr[], int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ",arr[i]);
//	}
//}
//void Reverse(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left < right)
//	{
//		int tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}


////将数组A中的内容和数组B中的内容进行交换
//void Swap(int arr1[], int arr2[], int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		int tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tmp;
//	}
//}



////打印整数二进制的奇数位和偶数位
//void Printbit(int num)
//{
//	for (int i = 31; i >= 1; i -= 2)
//	{
//		printf("%d ", (num >> i) & 1);
//	}
//	printf("\n");
//	for (int i = 30; i >= 0; i -= 2)
//	{
//		printf("%d ", (num >> i) & 1);
//	}
//	printf("\n");
//}



////统计二进制中1的个数
//int count_one_bit(int n)
//{
//	int count = 0;
//	while (n)
//	{
//		n = n & (n - 1);
//		count++;
//	}
//	return count;
//}
//
//class Solution {
//public:
//    int  NumberOf1(int n) {
//        int count = 0;
//        for (int i = 0; i < 32; i++)
//        {
//            if (n & (1 << i))
//                count++;
//        }
//        return count;
//    }
//};



////交换两个变量（不创建临时变量）
//int main()
//{
//	int a = 10;  
//	int b = 20;
//	a = a ^ b;   //c
//	b = a ^ b;   //a
//	a = a ^ b;   //b
//	printf("%d %d\n", a, b);
//	return 0;
//}