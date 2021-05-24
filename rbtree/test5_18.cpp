#define _CRT_SECURE_NO_WARNINGS
#include<utility>
#include<iostream>
using namespace std;

enum COLOR
{
	BLACK��
	RED;
};

template<class K,class V>
struct RBNode
{
	//typedef bool color;
	RBNode<K, V>* _parent;
	RBNode<K, V>* _left;
	RBNode<K, V>* _right;

	//key-val
	pair<K, V> _kv;
	//��ɫ
	COLOR _color;

	RBNode(const pair<K, V>& kv = pair<K, V>())
		:_parent(nullptr)
		, _left(nullptr)
		, _right(nullptr)
		, _kv(kv),
		,_color(RED)
	{}
};

template <class K, class V>
class RBTree
{
public:
	typedef RBNode<K, V> Node;

	RBTree()
		:_header(new Node)
	{
		//��������
		_header->_left = _header->_right = _header;
	}

	bool insert(const pair<K, V>& kv)
	{
		//1.�������Ĳ���
		//������_header->_parent:nullptr
		if (_header->_parent == nullptr)
		{
			Node* root = new Node(kv);

			_header->_parent = root;
			root->_parent = _header;
			_header->_left = _header->_right = root;

			//���ڵ��Ǻ�ɫ
			root->_color = BLACK;
			return true;
		}

		//�Ӹ��ڵ㿪ʼ����
		Node* cur = _header->_parent;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			//�������kֵ��keyֵ���бȽ�
			//kv:pair<K,V>, key:pair.first
			if (cur->_kv.first == kv.first)
			{
				//keyֵ�������ظ�
				return false;
			}
			else if (cur->_kv.first > kv.first)
			{
				cur = cur->_left;
			}
			else
			{
				cur = cur->_right;
			}
		}
		//����������Ľڵ�
		cur = new Node(kv);
		if (parent->_kv.first > cur->_kv.first)
			parent->_left = cur;
		else
			parent->_right = cur;
		cur->_parent = parent;

		//2.�޸���ɫ���ߵ����ṹ
		//�ж��Ƿ��к�ɫ�����Ľڵ�
		while (cur != _header->_parent && cur->_parent->_color == RED)
		{
			parent = cur->_parent;
			Node* gfather = parent->_parent;

			if (gfather->_left == parent)
			{
				Node* uncle = gfather->_right;
				//1.uncle���ڵģ�������ɫΪ��ɫ
				if (uncle && uncle->_color == RED)
				{
					parent->_color = uncle->_color = BLACK;
					gfather->_color = RED;
					//��������
					cur = gfather;
				}
				else
				{
					//�ж��Ƿ�Ϊ˫������
					if (cur == parent->_right)
					{
						//����
						RotateL(parent);
						//����cur��parentָ���˻��������ĳ���
						swap(cur, parent);
					}
					//����
					rotateR(gfather);
					parent->_color = BLACK;
					gfather->_color = RED;
					break;
				}
			}
			else
			{
				//gfather->_right == parent
				Node* uncle = gfather->_left;
				if (uncle && uncle->_color == RED)
				{
					parent->_color = uncle->_color = BLACK;
					gfather->_color = RED;
					//��������
					cur = gfather;
				}
				else
				{
					//�ж��Ƿ�Ϊ˫������
					if (cur == parent->_left)
					{
						//����
						RotateR(parent);
						//����
						swap(cur, parent);
					}
					
					//����
					RotateL(gfather);
					parent->_color = BLACK;
					gfather->_color = RED;
					break;
				}
			}

		}
		//���ڵ����ɫ�ĳɺ�ɫ
		_header->_parent->_color = BLACK;
		//����header������ָ��
		//_header->_left = leftMost();
		//_header->_right = rightMost();
	}

	//  parent
	//            subR
	//       subRL
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		subR->_left = parent;
		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		//�жϸ�
		if (parent == _header->_parent)
		{
			_header->_parent = subR;
			subR->_parent = _header;
		}
		else
		{
			Node* pparent = parent->_parent;
			if (pparent->_left == parent)
				pparent->_left = subR;
			else
				pparent->_right = subR;
			sub->_parent = pparent;
		}
		parent->_parent = subR;
	}

	//      parent
	//subL
	//    subLR
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		subL->_right = parent;
		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		//�жϸ�
		if (parent == _header->_parent)
		{
			_header->_parent = subL;
			subL->_parent = _header;
		}
		else
		{
			Node* pparent = parent->_parent;
			if (pparent->_left == parent)
				pparent->_left = subL;
			else
				pparent->_right = subL;
			subL->_parent = pparent;
		}
		parent->_parent = subL;
	}

private:
	//��Ա��header
	Node* _header;
};


void test()
{
	RBTree<int, int> rbt;
	rbt.insert(make_pair(10, 10));
	rbt.insert(make_pair(15, 15));
	rbt.insert(make_pair(5, 5));
	rbt.insert(make_pair(2, 2));
}
int main()
{
	test();
	return 0;
}
