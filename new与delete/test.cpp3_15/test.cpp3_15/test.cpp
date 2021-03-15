#define _CRT_SECURE_NO_WARNINGS
//C++内存管理方式
//C语言内存管理方式在C++中可以继续使用，但有些地方就无能为力而且使用起来比较麻烦，
//因此C++又提出了自己的内存管理方式：通过new和delete操作符进行动态内存管理
//1.new/delete操作内置类型
//申请和释放单个元素的空间，使用new和delete操作符，
//申请和释放连续的空间，使用new[]和delete[]
void test()
{
	//动态申请一个int类型的空间
	//new:operator new-->malloc
	int* ptr = new int;
	//释放空间
	//delete:operator delete-->free
	delete ptr;

	//动态申请一个int类型的空间,并初始化为10
	int* ptr2 = new int(10);
	//释放空间
	delete ptr2;

	//动态申请10个int类型的空间,每个元素占4个字节，内容都为随机值
	//new[]:operator new[]-->operator new-->malloc
	int* ptr3 = new int[10];
	//释放空间
	//delete[]:operator delete[]-->operator delete-->free
	delete[] ptr3;
}


//new和delete操作自定义类型
//在申请自定义类型的空间时，new会调用构造函数，delete会调用析构函数，而malloc与free不会
class test
{
public:
	test()
		:_data(0)
	{
		cout << "test():" << this << endl;
	}
	~test()
	{
		cout << "~test():" << this << endl;
	}

private:
	int _data;
};
void Test()
{
	//申请单个test类型的空间
	test* p1 = (test*)malloc(sizeof(test));
	free(p1);

	//申请10个test类型的空间
	test* p2 = (test*)malloc(sizeof(test) * 10);
	free(p2);
}

void Test2()
{
	//自定义类型
	//new：operator new-->malloc-->构造
	test* p1 = new test;
	//delete:析构-->operator delete-->free
	delete p1;

	//new[]:operator new[]-->operator new-->malloc-->n次构造
	test* p2 = new test[10];
	//delete[]:n次析构-->operator delete[]-->operator delete-->free
}

//new和delete是用户进行动态内存申请和释放的操作符，operator new和operator delete是
//系统提供的全局函数u，new在底层调用operator new全局函数来申请空间，
//delete在底层通过operator delete全局函数来释放空间

//通过上述两个全局函数的实现知道，operator new 实际也是通过malloc来申请空间，如果malloc申请空间
//成功就直接返回，否则执行用户提供的空间不足应对措施，如果用户提供该措施就继续申请，否则就抛异
//常。operator delete 最终是通过free来释放空间的。




//下面代码演示了，针对链表的节点ListNode通过重载类专属 operator new / operator delete，实现链表节
//点使用内存池申请和释放内存，提高了效率
struct ListNode
{
public:
	void* operator new(size_t n)
	{
		cout << "operator new" << endl;
		//采用内存池的方式
		allocator<ListNode> alloc;
		return alloc.allocate(1);
		cout << "memory pool allocate" << endl;
	}

	void operator delete(void* ptr)
	{
		cout << "operator delete" << endl;
		allocator<ListNode> alloc;
		alloc.deallocate((ListNdoe*)ptr, 1);
		cout << "memory poll deallocate" << endl;
	}

	ListNode()
	{
		cout << "ListNode(int)" << endl;
	}
	~ListNode()
	{
		cout << "~ListNode" << endl;
	}

private:
	int _data = 0;
	ListNode* _next = nullptr;
};

void test()
{
	ListNode* node = new ListNode;
	delete node;
}


5. new和delete的实现原理
5.1 内置类型
如果申请的是内置类型的空间，new和malloc，delete和free基本类似，不同的地方是：new / delete申请和
释放的是单个元素的空间，new[]和delete[]申请的是连续空间，而且new在申请空间失败时会抛异常，
malloc会返回NULL。
5.2 自定义类型
new的原理
1. 调用operator new函数申请空间
 }
};
class List
{
public:
	List()
	{
		_head = new ListNode;
		_head->_next = _head;
		_head->_prev = _head;
	}
	~List()
	{
		ListNode* cur = _head->_next;
		while (cur != _head)
		{
			ListNode* next = cur->_next;
			delete cur;
			cur = next;
		}
		delete _head;
		_head = nullptr;
	}
private:
	ListNode* _head;
};
int main()
{
	List l;
	return 0;
}


