#define _CRT_SECURE_NO_WARNINGS
//求1 + 2 + 3 + ... + n，要求不能使用乘除法、for、while、if、else、switch、case
//等关键字及条件判断语句（A ? B : C）。
class Solution {
public:
    //内部类
    class Sum
    {
    public:
        Sum()
        {
            //直接访问外部类的静态成员
            _sum += _i;
            ++_i;
        }
    };
    int Sum_Solution(int n) {
        //重置
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



//给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转
class Solution {
public:
    string reverseOnlyLetters(string S) {
        char* pLeft = (char*)S.c_str();
        char* pRight = pLeft + (S.size() - 1);

        while (pLeft < pRight)
        {
            //从前往后找，找到一个字母
            while (pLeft < pRight)
            {
                if (isalpha(*pLeft))
                    break;
                ++pLeft;
            }

            //从后往前找，找到一个字母
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



//给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
class Solution {
public:
    int firstUniqChar(string s) {
        //统计每个字符出现的次数
        int count[256] = { 0 };
        int size = s.size();
        for (int i = 0; i < size; i++)
            count[s[i]] += 1;

        //按照字符次序从前往后找只出现一个的字符
        for (int i = 0; i < size; i++)
        {
            if (1 == count[s[i]])
                return i;
        }
        return -1;
    }
};



//计算字符串最后一个单词的长度，单词以空格隔开。
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



//给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
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
        //先把小写字母转化成大写字母，再进行判断
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