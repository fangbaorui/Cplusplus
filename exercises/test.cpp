//�ۼ�����
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



//��ӡ����,�������m��һ���еĵ�n�죬�����n���Ǽ��¼���
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


//���ڲ�ֵ,���������ڣ�����������֮�������������������������������ǹ涨����֮�������Ϊ����
#include <iostream>
using namespace std;
/*
*˼·��
* 1. �ֱ����ÿһ��������0000��0��1�վ��������
* 2. ������������������ɵõ�����������������
*/
//ƽ���1�µ�n�µ�����
int mon[12] = { 0,31,59,90,120,151,181,212,243,273,304,334 };
//���������գ��������0000��0��1�յ�������
int CountDay(int y, int m, int d)
{
    // ����0-y�������
    int yearDay = y * 365 + y / 4 - y / 100 + y / 400;
    // ���㵽0-m�µ�����
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



//����һ��ĵڼ���,������������ڣ���������һ��ĵڼ��졣
#include<iostream>
using namespace std;
/*
*˼·��
* 1. ͨ��ö��ÿ���µ�1������һ��ĵڼ��죬�Ӷ������ۼ���ͼ��ɣ�����ע������Ĵ���
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



//��1 + 2 + 3 + ... + n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A ? B : C)
//2. �������C++���ԣ���������캯�����Զ����õ��ص㣬������ڹ��캯���н������
// 3. �������ж���Ҫ�����ͬ�ĺͽ��и��£��������Ա����Ϊstatic
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