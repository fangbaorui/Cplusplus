//剑指 Offer II 116. 朋友圈
//一个班上有 n 个同学，其中一些彼此是朋友，另一些不是。朋友关系是可以传递的，
//如果 a 与 b 直接是朋友，且 b 与 c 是直接朋友，那么 a 与 c 就是间接朋友。
//定义 朋友圈 就是一组直接或者间接朋友的同学集合。
//给定一个 n x n 的矩阵 isConnected 表示班上的朋友关系，其中 isConnected[i][j] = 1 表示第 i 个同学
//和第 j 个同学是直接朋友，而 isConnected[i][j] = 0 表示二人不是直接朋友
#include<iostream>
#include<vector>
using namespace std;
class UnionFindSet
{
public:
	//初始化，将数组中的元素全部设置成-1
	UnionFindSet(size_t size)
		:_ufs(size,-1)
	{}

	//UnionFindSet(size_t size)
	//{
	//	_ufs.resize(size, -1);
	//}

	//查找X所在的根集合
	int FindRoot(int x)
	{
		while (_ufs[x] >= 0)
		{
			x = _ufs[x];
		}
		return x;
	}
	//x1和x2所在的集合合并
	bool Union(int x1, int x2)
	{
		int root1 = FindRoot(x1);
		int root2 = FindRoot(x2);

		if (root1 != root2)
		{
			_ufs[root1] += _ufs[root2];
			_ufs[root2] = root1;
			return true;
		}
		return false;
	}

	//数组中负数中的个数，即为集合的个数
	size_t Count() const
	{
		size_t count = 0;
		for (auto e : _ufs)
		{
			if (e < 0)
				count++;
		}
		return count;
	}
private:
	vector<int> _ufs;
};
class Solution {
public:
	int findCircleNum(vector<vector<int>>& M) {
		UnionFindSet ufs(M.size());
		for (int i = 0; i < M.size(); i++)
		{
			for (int j = 0; j < M[i].size(); j++)
			{
				//自己和自己的关系除外
				if (i == j)
					continue;
				//如果i和j是朋友，将其添加到一个朋友圈
				if (1 == M[i][j])
				{
					ufs.Union(i, j);
				}
			}
		}
		return ufs.Count();
	}
};





//990. 等式方程的可满足性
//给定一个由表示变量之间关系的字符串方程组成的数组，每个字符串方程 equations[i] 的长度为 4，
//并采用两种不同的形式之一："a==b" 或 "a!=b"。在这里，a 和 b 是小写字母（不一定不同），表示单字母变量名。
//
//只有当可以将整数分配给变量名，以便满足所有给定的方程时才返回 true，否则返回 false。
//提示：
//1 <= equations.length <= 500
//equations[i].length == 4
//equations[i][0] 和 equations[i][3] 是小写字母
//equations[i][1] 要么是 '='，要么是 '!'
//equations[i][2] 是 '='
#include<iostream>
#include<vector>
using namespace std;
class UnionFindSet
{
public:
	//初始化，将数组中的元素全部设置成-1
	UnionFindSet(size_t size)
		:_ufs(size, -1)
	{}

	//UnionFindSet(size_t size)
	//{
	//	_ufs.resize(size, -1);
	//}

	//查找X所在的根集合
	int FindRoot(int x)
	{
		while (_ufs[x] >= 0)
		{
			x = _ufs[x];
		}
		return x;
	}
	//x1和x2所在的集合合并
	bool Union(int x1, int x2)
	{
		int root1 = FindRoot(x1);
		int root2 = FindRoot(x2);

		if (root1 != root2)
		{
			_ufs[root1] += _ufs[root2];
			_ufs[root2] = root1;
			return true;
		}
		return false;
	}

	//数组中负数中的个数，即为集合的个数
	size_t Count() const
	{
		size_t count = 0;
		for (auto e : _ufs)
		{
			if (e < 0)
				count++;
		}
		return count;
	}
private:
	vector<int> _ufs;
};
class Solution {
public:
	bool equationsPossible(vector<string>& equations) {
		//将所有==两端的字符合并到一个集合
		//检测！=两端的字符是否在同一个集合，如果存在则不满足，如果不存在则满足
		UnionFindSet ufs(26);
		for (int i = 0; i < equations.size(); i++)
		{
			if ('=' == equations[i][1])
			{
				ufs.Union(equations[i][0] - 'a', equations[i][3] - 'a');
			}
		}

		for (int i = 0; i < equations.size(); i++)
		{
			if ('!' == equations[i][1])
			{
				if (ufs.FindRoot(equations[i][0] - 'a') == ufs.FindRoot(equations[i][3] - 'a'))
					return false;
			}
		}
		return true;
	}
};