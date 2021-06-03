#include<iostream>
#include<mutex>
using namespace std;

mutex mtx;

//������
template <class Mtx>
class LockGuard
{
public:
	LockGuard(Mtx& mtx)
		:_mtx(mtx)
	{
		_mtx.lock();
	}

	~LockGuard()
	{
		_mtx.unlock();
	}

	//������
	LockGuard(const LockGuard<Mtx>& lg) = delete;
	LockGuard& operator=(const LockGuard<Mtx>& lg) = delete;

private:
	Mtx& _mtx;
};

void fun1()
{
	LockGuard<mutex> lg(mtx); //���return��,Ҳ������
	//mtx.lock();
	cout << "fun1()" << endl;
	int n;
	cin >> n;
	if (n == 0)
		return;
	//mtx.unlock(); //��������ˣ��Ͳ��ܽ���������ɶ���
}
void fun2()
{
	LockGuard<mutex> lg(mtx);
	//mtx.lock();
	cout << "fun2()" << endl;
	//mtx.unlock();
}
void test()
{
	thread t1(fun1); 
	thread t2(fun2);
	t1.join();
	t2.join();
}
int main()
{
	test();
	return 0;
}