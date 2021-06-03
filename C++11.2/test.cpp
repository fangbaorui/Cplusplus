#include<iostream>
#include<mutex>
using namespace std;

mutex mtx;

//守卫锁
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

	//防拷贝
	LockGuard(const LockGuard<Mtx>& lg) = delete;
	LockGuard& operator=(const LockGuard<Mtx>& lg) = delete;

private:
	Mtx& _mtx;
};

void fun1()
{
	LockGuard<mutex> lg(mtx); //如果return了,也能析构
	//mtx.lock();
	cout << "fun1()" << endl;
	int n;
	cin >> n;
	if (n == 0)
		return;
	//mtx.unlock(); //如果返回了，就不能解锁，会造成堵塞
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