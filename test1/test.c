//ʵ��һ���������ж�һ�����ǲ���������
//��������ʵ�ֵĺ�����ӡ100��200֮���������
#include<stdio.h>
//#include<math.h>
//int is_prime(int n)
//{
//	int k = (int)sqrt(n);
//	for (int i = 2; i <= k; i++)
//	{
//		if (n % i == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//int main()
//{
//	for (int i = 100; i <= 200; i++)
//	{
//		if (is_prime(i))
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}



////ʵ�ֺ����ж�year�ǲ������ꡣ
//int is_leap_year(int year)
//{
//	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//		return 1;
//	else
//		return 0;
//}



////ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ��
////�磺����9�����9 * 9�ھ������12�����12 * 12�ĳ˷��ھ���
//void PrintMulTable(int n)
//{
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			printf("%d * %d = %3d", i, j, i * j);
//		}
//		printf("\n");
//	}
//}


////�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ
//void print(int n)
//{
//	if (n > 9)
//		print(n / 10);
//	printf("%d", n % 10);
//}
//int main()
//{
//	print(123);
//	return 0;
//}



////�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳ˣ���������������⣩
//long long fac(int n)
//{
//	if (n <= 1)
//		return 1;
//	else
//		return n * fac(n - 1);
//}
//
//long long facnon(int n)
//{
//	long long ret = 1;
//	while (n)
//	{
//		ret *= n;
//		n--;
//	}
//	return ret;
//}

////�ݹ�ͷǵݹ�ֱ�ʵ��strlen
//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		str++;
//		count++;
//	}
//	return count;
//}
//
//int my_strlen(char* str)
//{
//	if (*str == '\0')
//		return 0;
//	else
//		return 1 + my_strlen(str + 1);
//}



//�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲�������
int fib(int n)
{
	if (n <= 2)
		return 1;
	else
		return fib(n - 1) * fib(n - 2);
}
int fibNon(int n)
{
	if (n <= 2)
		return 1;
	int f1 = 1;
	int f2 = 1;
	int f3 = 2;
	for(int i = 3; i <= n; i++)
	{
		f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
	}
	return f3;
}
int main()
{
	int ret = fibNon(5);
	printf("%d", ret);
	return 0;
}