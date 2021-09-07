#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int map[4][2] = { {0,1}, {1,0}, {0,-1},{-1, 0} };
//ij是入口坐标，xy是出口坐标
bool BFS(vector<vector<int>>& grid, int i, int j, int x, int y)
{
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	int row = grid.size();
	int col = grid[0].size();
	vector<vector<int>> visited(row, vector<int>(col, 0));

	while (!q.empty())
	{
		//获取队头元素
		pair<int, int> top = q.front();
		q.pop();
		//如果找到出口坐标，返回真
		if (top.first == x && top.second == y)
			return true;
		//搜索:上下左右
		for (int i = 0; i < 4; i++)
		{
			int nexti = i + map[i][0];
			int nextj = j + map[i][1];
			if (nexti < 0 || nexti >= row || nextj < 0 || nextj >= col)
				continue;
			//没有障碍且没有访问过的节点入队
			if (grid[nexti][nextj] == 0 && visited[nexti][nextj] == 0)
			{
				visited[nexti][nextj] = 1;
				q.push(make_pair(nexti, nextj));
			}
		}
	}
	return false;
}
int main()
{
	int i, j, x, y;
	int row, col;
	cout << "请输入迷宫的大小：行和列" << endl;
	cin >> row >> col;
	vector<vector<int>> grid(row, vector<int>(col));
	cout << "请输入迷宫的元素" << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> grid[i][j];
		}
	}
	while (1)
	{
		cout << "请输入迷宫入口和出口坐标" << endl;
		cin >> i >> j >> x >> y;
		cout << "是否可以走出迷宫：" << BFS(grid, i, j, x, y) << endl;
	}
	return 0;
}