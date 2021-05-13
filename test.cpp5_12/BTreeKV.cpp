#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
template <class K,class V>
struct BNode
{
	K _key;  //����
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

	//�������������������ݺͽṹ
	Node* copy(Node* root)
	{
		if (root == nullptr)
			return nullptr;

		Node* newNode = new Node(root->_key,root->_value);
		newNode->_left = copy(root->_left);
		newNode->_right = copy(root->_right);
		return newNode;
	}

	//��������
	BTree(const BTree<K,V>& btree)
		:_root(copy(btree._root))
	{}

	BTree()
		:_root(nullptr)
	{}

	//�������ظ���ֵ
	bool insert(const K& key,const V& value)
	{
		//�����һ��ֵ
		if (_root == nullptr)
		{
			_root = new Node(key,value);
			return true;
		}

		//�ҵ���Ҫ����Ԫ�ص�λ��
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

		//����
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

	//�������������������
	void _inorder(Node* root)
	{
		if (root)
		{
			_inorder(root->_left);
			cout << root->_key << "-->"<<root->_value<<" ";
			_inorder(root->_right);
		}
	}

	//����
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
		//����
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

		//ɾ��
		//1.ɾ����ΪҶ�ӽڵ�
		if (cur->_left == nullptr && cur->_right == nullptr)
		{
			//�ж��Ƿ�Ϊ���ڵ�
			if (cur == _root)
			{
				_root = nullptr;
			}
			else
			{
				//�ж���Ҫɾ���ĸ��ڵ�����һ��
				if (parent->_left == cur)
					parent->_left = nullptr;
				else
					parent->_right = nullptr;
			}
			//ɾ���ڵ�
			delete cur;
		}
		else if (cur->_left == nullptr)  //��Ϊ��
		{
			//�ж��Ƿ�Ϊ���ڵ�
			if (cur == _root)
			{
				//���¸��ڵ�
				_root = cur->_right;
			}
			else
			{
				if (parent->_left == cur)
					parent->_left = cur->_right;
				else
					parent->_right = cur->_right;
			}
			//ɾ���ڵ�
			delete cur;
		}
		else if (cur->_right == nullptr)
		{
			//�ж��Ƿ�Ϊ���ڵ�
			if (cur == _root)
			{
				//���¸��ڵ�
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
			//��������������
			//1.�����������������ҽڵ�
			Node* leftRightMost = cur->_left;
			parent = cur;
			while (leftRightMost->_right)
			{
				parent = leftRightMost;
				leftRightMost = leftRightMost->_right;
			}

			//2.����
			swap(cur->_key, leftRightMost->_key);
			swap(cur->_value, leftRightMost->_value);
			//3.ɾ�����ҽڵ�
			if (parent->_left == leftRightMost)
				parent->_left = leftRightMost->_left;
			else
				parent->_right = leftRightMost->_left;

			//4.ɾ�����ҽڵ�
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