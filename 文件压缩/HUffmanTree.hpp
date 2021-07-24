#pragma once
#include <queue>
#include <vector>
#include <functional>
// ʵ��huffman��
template<class W>
struct HTNode
{
	HTNode(const W& w)
		: left(nullptr)
		, right(nullptr)
		, parent(nullptr)
		, weight(w)
	{}

	HTNode<W>* left;
	HTNode<W>* right;
	HTNode<W>* parent;
	W weight;
};


template<class W>
struct Compare
{
	bool operator()(const HTNode<W>* left, const HTNode<W>* right)
	{
		return left->weight > right->weight;
	}
};


template<class W>
class HuffmanTree
{
public:
	HuffmanTree()
		: root(nullptr)
	{}

	~HuffmanTree()
	{
		DestroyTree(root);
	}

	void CreateHuffmanTree(const W array[], size_t size, const W& invalid)
	{
		// 1. �ȴ���n��ֻ�и��ڵ�Ķ�����ɭ��
		std::priority_queue<HTNode<W>*, std::vector<HTNode<W>*>, Compare<W>>  q;
		for (size_t i = 0; i < size; ++i)
		{
			if (array[i] != invalid)
				q.push(new HTNode<W>(array[i]));
		}

		// 2.
		while (q.size() > 1)
		{
			// �Ӷ�����ɭ����ȡȨֵ��С�����Ŷ�����
			HTNode<W>* left = q.top();
			q.pop();
			HTNode<W>* right = q.top();
			q.pop();

			// ��left��right��Ϊһ���½ڵ�����Һ��ӣ�
			// �½ڵ��е�Ȩֵ���������Һ��ӽڵ���Ȩֵ֮��

			HTNode<W>* parent = new HTNode<W>(left->weight + right->weight);
			parent->left = left;
			parent->right = right;

			left->parent = parent;
			right->parent = parent;

			// �������õ��¶�������ص����ȼ�������
			q.push(parent);
		}

		// ��ɭ����ֻʣ��һ����������huffman��
		root = q.top();
	}

	void DestroyTree(HTNode<W>*& pRoot)
	{
		if (pRoot)
		{
			DestroyTree(pRoot->left);
			DestroyTree(pRoot->right);
			delete pRoot;
			pRoot = nullptr;
		}
	}

	HTNode<W>* GetRoot()
	{
		return root;
	}

private:
	HTNode<W>* root;
};



