#define _CRT_SECURE_NO_WARNINGS
#include<time.h>
#include<iostream>
using namespace std;

template <class T>
struct BNode
{
	T _data;
	typedef BNode<T> Node;
	Node* _left;
	Node* _right;

	BNode(const T& data)
		:_data(data)
		, _left(nullptr)
		, _right(nullptr)
	{}
};

template <class T>
class BTree
{
public:
	typedef BNode<T> Node;

	Node* find(const T& val)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_data == val)
				return cur;
			else if (cur->_data > val)
				cur = cur->_left;
			else
				cur = cur->_right;
		}
	}

	//拷贝二叉搜索树的数据和结构
	Node* copy(Node* root)
	{
		if (root == nullptr)
			return nullptr;

		Node* newNode = new Node(root->_data);
		newNode->_left = copy(root->_left);
		newNode->_right = copy(root->_right);
		return newNode;
	}

	//拷贝构造
	BTree(const BTree<T>& btree)
		:_root(copy(btree._root))
	{}

	BTree()
		:_root(nullptr)
	{}

	//不插入重复的值
	bool insert(const T& val)
	{
		//插入第一个值
		if (_root == nullptr)
		{
			_root = new Node(val);
			return true;
		}

		//找到需要插入元素的位置
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->_data == val)
				return false;
			else if (cur->_data > val)
				cur = cur->_left;
			else
				cur = cur->_right;
		}

		//插入，val小于parent的值，放在左边，如果大于parent，放在右边
		cur = new Node(val);
		if (parent->_data > val)
			parent->_left = cur;
		else
			parent->_right = cur;
		return true;
	}

	//搜索树的中序遍历有序，从小到大排序
	void inorder()
	{
		_inorder(_root);
		cout << endl;
	}
	void _inorder(Node* root)
	{
		if (root)
		{
			_inorder(root->_left);
			cout << root->_data << " ";
			_inorder(root->_right);
		}
	}

	//销毁
	void destroy(Node* root)
	{
		if (root)
		{
			destroy(root->_left);
			destroy(root->_right);
			cout << "destroy:" << root->_data << endl;
			delete root;
		}
	}

	~BTree()
	{
		if (_root)
		{
			destroy(_root);
			_root = nullptr;
		}
	}
private:
	Node* _root;
};

//生成随机数，然后进行中序遍历
void test()
{
	BTree<int> b;
	srand(time(nullptr));
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		b.insert(rand());
	}

	b.inorder();

	BTree<int> copy(b);
	copy.inorder();
}

//void test()
//{
//	BTree<int> b;
//	b.insert(50);
//	b.insert(90);
//	b.insert(30);
//	b.insert(20);
//	b.insert(80);
//	b.insert(40);
//	b.insert(70);
//	b.insert(5);
//	b.insert(500);
//
//	//中序遍历有序
//	b.inorder();
//}

int main()
{
	test();
	return 0;
}