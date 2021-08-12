#include<iostream>
#include<assert.h>
using namespace std;
/*����һ: string�Ĵ�ͳ��ʵ��*/
class string
{
public:
    //���캯��
    string(const char* str = "")
    {
        // ����string�����ʱ���������nullptrָ�룬��Ϊ����Ƿ����˴�������
        if (nullptr == str)
        {
            assert(false);
            return;
        }
        _str = new char[strlen(str) + 1];
        strcpy(_str, str);
    }

    //�������캯��
    string(const string& s)
        : _str(new char[strlen(s._str) + 1])
    {
        strcpy(_str, s._str);
    }

    //��ֵ��� �����׶ε�ʵ�֣���������쳣��ȫ�����Բο���ָofferһ���������1
    string& operator=(const string& s)
    {
        if (this != &s)
        {
            delete[]_str;
            _str = new char[strlen(s._str) + 1];
            strcpy(_str, s._str);
        }
        return *this;
    }

    //��������
    ~string()
    {
        delete[]_str;
        _str = nullptr;
    }
private:
    char* _str;
};


/*������: String����ʱ���󽻻��ִ���*/
class string
{
public:
    //���캯�� ����strΪ�յ�����
    string(const char* str = "")
    {
        if (nullptr == str)
            str = "";
        _str = new char[strlen(str) + 1];
        strcpy(_str, str);
    }

    //�������캯�� ͨ����ʱ����Ľ�����ʽ���п������죬����������֮ǰʵ�ֵ���ͨ���캯��������   
    //����,Ȼ��ͨ������������ڲ�ָ���ָ�򣬴Ӷ��ﵽ����������󣬺ô���������������������  
    //���캯���Ĵ��������൱�ڰѴ������չ��Ϊ���캯��
    string(const string& s)
        : _str(nullptr)
    {
        string strTmp(s._str);
        swap(_str, strTmp._str);
    }

    //��ֵ��� ͨ����ʱ����Ľ�����ʽ����ʵ�֣�
    //��������쳣��ȫ�����Բο���ָofferһ���������1
    //���ֽ�����ʽ�ڸ�ֵ����У�������Ԥ���ڴ�й©����Ϊ������ɵ���ʱ����һ�������������   
    //�����ͻ��Զ������������������ͷŶ�Ӧ����Դ
    string& operator=(const string& s)
    {
        if (this != &s)
        {
            string strTmp(s);
            swap(_str, strTmp._str);
        }
        return *this;
    }

    //��������,��_str��Ϊ��ʱ�Ž����ͷŹ������������鷽ʽ�����ͷ�
    ~string()
    {
        if (_str)
        {
            delete[] _str;
            _str = nullptr;
        }
    }
private:
    char* _str;
};