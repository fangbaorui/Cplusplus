
#include<stdio.h>
////��дһ������ʵ��n��k�η���ʹ�õݹ�ʵ�֡�
//int Pow(int n, int k)
//{
//	if (k == 1)
//		return n;
//	else
//		return n * Pow(n, k - 1);
//}


////����һ������ÿλ֮�ͣ��ݹ�ʵ�֣�
//int DigitSum(int n)
//{
//	if (n > 9)
//		return n % 10 + DigitSum(n / 10);
//	else
//		return n;
//}


////�ַ�������
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


////ʵ��һ�������������ð������
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


////������A�е����ݺ�����B�е����ݽ��н���
//void Swap(int arr1[], int arr2[], int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		int tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tmp;
//	}
//}



////��ӡ���������Ƶ�����λ��ż��λ
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



////ͳ�ƶ�������1�ĸ���
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



////����������������������ʱ������
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