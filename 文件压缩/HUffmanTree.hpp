#pragma once
#include <queue>
#include <vector>
#include <functional>
// 实现huffman树
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
		// 1. 先创建n个只有根节点的二叉树森林
		std::priority_queue<HTNode<W>*, std::vector<HTNode<W>*>, Compare<W>>  q;
		for (size_t i = 0; i < size; ++i)
		{
			if (array[i] != invalid)
				q.push(new HTNode<W>(array[i]));
		}

		// 2.
		while (q.size() > 1)
		{
			// 从二叉树森林中取权值较小的两颗二叉树
			HTNode<W>* left = q.top();
			q.pop();
			HTNode<W>* right = q.top();
			q.pop();

			// 以left和right作为一个新节点的左右孩子，
			// 新节点中的权值就是其左右孩子节点中权值之和

			HTNode<W>* parent = new HTNode<W>(left->weight + right->weight);
			parent->left = left;
			parent->right = right;

			left->parent = parent;
			right->parent = parent;

			// 将创建好的新二叉树插回到优先级队列中
			q.push(parent);
		}

		// 当森林中只剩余一棵树，就是huffman树
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



