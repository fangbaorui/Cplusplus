#define _CRT_SECURE_NO_WARNINGS
//��1 + 2 + 3 + ... + n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case
//�ȹؼ��ּ������ж���䣨A ? B : C����
class Solution {
public:
    //�ڲ���
    class Sum
    {
    public:
        Sum()
        {
            //ֱ�ӷ����ⲿ��ľ�̬��Ա
            _sum += _i;
            ++_i;
        }
    };
    int Sum_Solution(int n) {
        //����
        _sum = 0;
        _i = 1;

        Sum array[n];
        return _sum;
    }
private:
    static int _i;
    static int _sum;
};
int Solution::_i = 1;
int Solution::_sum = 0;



//����һ���ַ��� S������ ����ת��ġ� �ַ��������в�����ĸ���ַ���������ԭ�أ���������ĸ��λ�÷�����ת
class Solution {
public:
    string reverseOnlyLetters(string S) {
        char* pLeft = (char*)S.c_str();
        char* pRight = pLeft + (S.size() - 1);

        while (pLeft < pRight)
        {
            //��ǰ�����ң��ҵ�һ����ĸ
            while (pLeft < pRight)
            {
                if (isalpha(*pLeft))
                    break;
                ++pLeft;
            }

            //�Ӻ���ǰ�ң��ҵ�һ����ĸ
            while (pLeft < pRight)
            {
                if (isalpha(*pRight))
                    break;
                --pRight;
            }

            if (pLeft < pRight)
            {
                swap(*pLeft, *pRight);
                ++pLeft;
                --pRight;
            }
        }
        return S;
    }
};



//����һ���ַ������ҵ����ĵ�һ�����ظ����ַ���������������������������ڣ��򷵻� -1��
class Solution {
public:
    int firstUniqChar(string s) {
        //ͳ��ÿ���ַ����ֵĴ���
        int count[256] = { 0 };
        int size = s.size();
        for (int i = 0; i < size; i++)
            count[s[i]] += 1;

        //�����ַ������ǰ������ֻ����һ�����ַ�
        for (int i = 0; i < size; i++)
        {
            if (1 == count[s[i]])
                return i;
        }
        return -1;
    }
};



//�����ַ������һ�����ʵĳ��ȣ������Կո������
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string line;
    while (getline(cin, line))
    {
        size_t pos = line.rfind(' ');
        cout << line.size() - pos - 1 << endl;
    }
    return 0;
}



//����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��
class Solution {
public:
    bool isLetterOrNumber(char ch)
    {
        return (ch >= '0' && ch <= '9')
            || (ch >= 'a' && ch <= 'z')
            || (ch >= 'A' && ch <= 'Z');
    }
    bool isPalindrome(string s)
    {
        //�Ȱ�Сд��ĸת���ɴ�д��ĸ���ٽ����ж�
        for (auto& ch : s)
        {
            if (ch >= 'a' && ch <= 'z')
                ch -= 32;
        }

        int begin = 0;
        int end = s.size() - 1;
        while (begin < end)
        {
            while (begin < end && !isLetterOrNumber(s[begin]));
            ++begin;
            while (begin < end && !isLetterOrNumber(s[end]));
            --end;

            if (s[begin] != s[end])
            {
                return false;
            }
            else
            {
                ++begin;
                --end;
            }
        }
        return true;
    }
};