#define _CRT_SECURE_NO_WARNINGS
//C++�ڴ����ʽ
//C�����ڴ����ʽ��C++�п��Լ���ʹ�ã�����Щ�ط�������Ϊ������ʹ�������Ƚ��鷳��
//���C++��������Լ����ڴ����ʽ��ͨ��new��delete���������ж�̬�ڴ����
//1.new/delete������������
//������ͷŵ���Ԫ�صĿռ䣬ʹ��new��delete��������
//������ͷ������Ŀռ䣬ʹ��new[]��delete[]
void test()
{
	//��̬����һ��int���͵Ŀռ�
	//new:operator new-->malloc
	int* ptr = new int;
	//�ͷſռ�
	//delete:operator delete-->free
	delete ptr;

	//��̬����һ��int���͵Ŀռ�,����ʼ��Ϊ10
	int* ptr2 = new int(10);
	//�ͷſռ�
	delete ptr2;

	//��̬����10��int���͵Ŀռ�,ÿ��Ԫ��ռ4���ֽڣ����ݶ�Ϊ���ֵ
	//new[]:operator new[]-->operator new-->malloc
	int* ptr3 = new int[10];
	//�ͷſռ�
	//delete[]:operator delete[]-->operator delete-->free
	delete[] ptr3;
}


//new��delete�����Զ�������
//�������Զ������͵Ŀռ�ʱ��new����ù��캯����delete�����������������malloc��free����
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
	//���뵥��test���͵Ŀռ�
	test* p1 = (test*)malloc(sizeof(test));
	free(p1);

	//����10��test���͵Ŀռ�
	test* p2 = (test*)malloc(sizeof(test) * 10);
	free(p2);
}

void Test2()
{
	//�Զ�������
	//new��operator new-->malloc-->����
	test* p1 = new test;
	//delete:����-->operator delete-->free
	delete p1;

	//new[]:operator new[]-->operator new-->malloc-->n�ι���
	test* p2 = new test[10];
	//delete[]:n������-->operator delete[]-->operator delete-->free
}

//new��delete���û����ж�̬�ڴ�������ͷŵĲ�������operator new��operator delete��
//ϵͳ�ṩ��ȫ�ֺ���u��new�ڵײ����operator newȫ�ֺ���������ռ䣬
//delete�ڵײ�ͨ��operator deleteȫ�ֺ������ͷſռ�

//ͨ����������ȫ�ֺ�����ʵ��֪����operator new ʵ��Ҳ��ͨ��malloc������ռ䣬���malloc����ռ�
//�ɹ���ֱ�ӷ��أ�����ִ���û��ṩ�Ŀռ䲻��Ӧ�Դ�ʩ������û��ṩ�ô�ʩ�ͼ������룬���������
//����operator delete ������ͨ��free���ͷſռ�ġ�




//���������ʾ�ˣ��������Ľڵ�ListNodeͨ��������ר�� operator new / operator delete��ʵ�������
//��ʹ���ڴ��������ͷ��ڴ棬�����Ч��
struct ListNode
{
public:
	void* operator new(size_t n)
	{
		cout << "operator new" << endl;
		//�����ڴ�صķ�ʽ
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


5. new��delete��ʵ��ԭ��
5.1 ��������
�����������������͵Ŀռ䣬new��malloc��delete��free�������ƣ���ͬ�ĵط��ǣ�new / delete�����
�ͷŵ��ǵ���Ԫ�صĿռ䣬new[]��delete[]������������ռ䣬����new������ռ�ʧ��ʱ�����쳣��
malloc�᷵��NULL��
5.2 �Զ�������
new��ԭ��
1. ����operator new��������ռ�
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


