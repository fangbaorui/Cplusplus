#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
template <class K,class V>
struct BNode
{
	K _key;  //索引
	V _value;  //data
	typedef BNode<K,V> Node;
	Node* _left;
	Node* _right;

	BNode(const K& key,const V& value)
		:_key(key)
		,_value(value)
		, _left(nullptr)
		, _right(nullptr)
	{}
};

template <class K,class V>
class BTree
{
public:
	typedef BNode<K,V> Node;

	Node* find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key == key)
				return cur;
			else if (cur->_key > key)
				cur = cur->_left;
			else
				cur = cur->_right;
		}
		return cur;
	}

	//拷贝二叉搜索树的数据和结构
	Node* copy(Node* root)
	{
		if (root == nullptr)
			return nullptr;

		Node* newNode = new Node(root->_key,root->_value);
		newNode->_left = copy(root->_left);
		newNode->_right = copy(root->_right);
		return newNode;
	}

	//拷贝构造
	BTree(const BTree<K,V>& btree)
		:_root(copy(btree._root))
	{}

	BTree()
		:_root(nullptr)
	{}

	//不插入重复的值
	bool insert(const K& key,const V& value)
	{
		//插入第一个值
		if (_root == nullptr)
		{
			_root = new Node(key,value);
			return true;
		}

		//找到需要插入元素的位置
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->_key == key)
				return false;
			else if (cur->_key > key)
				cur = cur->_left;
			else
				cur = cur->_right;
		}

		//插入
		cur = new Node(key,value);
		if (parent->_key > key)
			parent->_left = cur;
		else
			parent->_right = cur;

		return true;
	}

	void inorder()
	{
		_inorder(_root);
		cout << endl;
	}

	//搜索树的中序遍历有序
	void _inorder(Node* root)
	{
		if (root)
		{
			_inorder(root->_left);
			cout << root->_key << "-->"<<root->_value<<" ";
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
			cout << "destroy:" << root->_key <<"-->"<<root->_value<<endl;
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

	bool erase(const K& key)
	{
		//查找
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (cur->_key == key)
				break;
			parent = cur;
			if (cur->_key > key)
				cur = cur->_left;
			else
				cur = cur->_right;
		}

		//删除
		//1.删除的为叶子节点
		if (cur->_left == nullptr && cur->_right == nullptr)
		{
			//判断是否为根节点
			if (cur == _root)
			{
				_root = nullptr;
			}
			else
			{
				//判断需要删除的父节点在哪一边
				if (parent->_left == cur)
					parent->_left = nullptr;
				else
					parent->_right = nullptr;
			}
			//删除节点
			delete cur;
		}
		else if (cur->_left == nullptr)  //左为空
		{
			//判断是否为根节点
			if (cur == _root)
			{
				//更新根节点
				_root = cur->_right;
			}
			else
			{
				if (parent->_left == cur)
					parent->_left = cur->_right;
				else
					parent->_right = cur->_right;
			}
			//删除节点
			delete cur;
		}
		else if (cur->_right == nullptr)
		{
			//判断是否为根节点
			if (cur == _root)
			{
				//更新根节点
				_root = cur->_left;
			}
			else
			{
				if (parent->_left == cur)
					parent->_left = cur->_left;
				else
					parent->_right = cur->_left;
			}
			delete cur;
		}
		else
		{
			//左右子树都存在
			//1.假设找左子树的最右节点
			Node* leftRightMost = cur->_left;
			parent = cur;
			while (leftRightMost->_right)
			{
				parent = leftRightMost;
				leftRightMost = leftRightMost->_right;
			}

			//2.交换
			swap(cur->_key, leftRightMost->_key);
			swap(cur->_value, leftRightMost->_value);
			//3.删除最右节点
			if (parent->_left == leftRightMost)
				parent->_left = leftRightMost->_left;
			else
				parent->_right = leftRightMost->_left;

			//4.删除最右节点
			delete leftRightMost;
		}

		return true;
	}
private:
	Node* _root;
};

void test()
{
	BTree<int,int> b;
	b.insert(5,50);
	b.insert(3,30);
	b.insert(7,70);
	b.insert(1,10);
	b.insert(4,40);
	b.insert(6,60);
	b.insert(8,80);
	b.insert(0,100);
	b.insert(2,20);
	b.insert(9,90);
	b.inorder();

	b.erase(5);
	b.inorder();
}

int main()
{
	test();
	return 0;
}