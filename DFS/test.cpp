#include<iostream>
#include<vector>
using namespace std;

void DFS(vector<int> box, vector<int> used, int idx)
{
	//边界
	if (idx == box.size())
	{
		for (int i = 1; i < box.size(); i++)
		{
			cout << box[i] << " ";
		}
		cout << endl;
		return;
	}
	//处理当前盒子
	for (int i = 1; i < box.size(); i++)
	{
		//判断当前牌是否用过
		if (used[i] == 0)
		{
			//当前没有使用的牌放进盒子
			box[idx] = i;
			used[i] = 1;

			//处理下一个盒子
			DFS(box, used, idx + 1);
			//回收当前使用的牌
			used[i] = 0;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> box(n + 1, 0);
	vector<int> used(n + 1, 0);
	DFS(box, used, 1);
	return 0;
}