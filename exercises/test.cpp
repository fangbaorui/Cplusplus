//累加天数
#include<iostream>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            int y, m, d, num;
            int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
            cin >> y >> m >> d >> num;
            while (num > days[m - 1])
            {
                if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
                    days[1] = 29;
                else
                    days[1] = 28;
                num -= days[m - 1] - d;
                d = 0;
                m++;
                if (m == 13)
                {
                    y++;
                    m = 1;
                }
            }
            printf("%4d-%02d-%02d\n", y, m, num);
        }
    }
    return 0;
}



//打印日期,给出年分m和一年中的第n天，算出第n天是几月几号
#include <iostream>
using namespace std;
int main()
{
    int year;
    int day;
    int mon[13] = { 31, 28, 31, 30, 31, 30, 31, 31, 30 ,31, 30, 31 };
    while (cin >> year >> day)
    {
        if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
            mon[1] = 29;
        else
            mon[1] = 28;
        for (int i = 0; i < 12; i++)
        {
            if (day <= mon[i])
            {
                printf("%04d-%02d-%02d\n", year, i + 1, day);
                break;
            }
            else
            {
                day = day - mon[i];
            }
        }
    }
    return 0;
}


//日期差值,有两个日期，求两个日期之间的天数，如果两个日期是连续的我们规定他们之间的天数为两天
#include <iostream>
using namespace std;
/*
*思路：
* 1. 分别求出每一个日期与0000年0月1日距离的天数
* 2. 两个距离天数相减即可得到两个日期相差的天数
*/
//平年从1月到n月的天数
int mon[12] = { 0,31,59,90,120,151,181,212,243,273,304,334 };
//给出年月日，计算距离0000年0月1日的天数和
int CountDay(int y, int m, int d)
{
    // 计算0-y年的天数
    int yearDay = y * 365 + y / 4 - y / 100 + y / 400;
    // 计算到0-m月的天数
    int monthDay = mon[m - 1];
    if (m > 2 && ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0))
        monthDay += 1;
    return yearDay + monthDay + d;
}
int main()
{
    int year1, month1, day1;
    scanf("%4d%2d%2d", &year1, &month1, &day1);
    int n1 = CountDay(year1, month1, day1);
    int year2, month2, day2;
    scanf("%4d%2d%2d", &year2, &month2, &day2);
    int n2 = CountDay(year2, month2, day2);
    cout << abs(n1 - n2) + 1 << endl;
}



//计算一年的第几天,根据输入的日期，计算是这一年的第几天。
#include<iostream>
using namespace std;
/*
*思路：
* 1. 通过枚举每个月的1号是这一年的第几天，从而进行累加求和即可，其中注意闰年的处理
*/
int main()
{
    int year, month, day;
    while (cin >> year >> month >> day)
    {
        int monthDays[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
        int nday = monthDays[month - 1] + day;
        if (month > 2 &&
            ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
        {
            nday += 1;
        }
        cout << nday << endl;
    }
    return 0;
}



//求1 + 2 + 3 + ... + n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A ? B : C)
//2. 充分利用C++特性，构造对象构造函数会自动调用的特点，让求和在构造函数中进行完成
// 3. 由于所有对象要针对相同的和进行更新，所以其成员定义为static
class Solution {
public:
    class Sum
    {
    public:
        Sum()
        {
            _sum += _i;
            _i++;
        }
    };
    int Sum_Solution(int n) {
        _i = 1;
        _sum = 0;
        Sum array[n];
        return _sum;
    }
    static size_t _sum;
    static size_t _i;
};



size_t Solution::_sum = 0;

size_t Solution::_i = 1;