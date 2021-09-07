#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int map[4][2] = { {0,1}, {1,0}, {0,-1},{-1, 0} };
//ij��������꣬xy�ǳ�������
bool BFS(vector<vector<int>>& grid, int i, int j, int x, int y)
{
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	int row = grid.size();
	int col = grid[0].size();
	vector<vector<int>> visited(row, vector<int>(col, 0));

	while (!q.empty())
	{
		//��ȡ��ͷԪ��
		pair<int, int> top = q.front();
		q.pop();
		//����ҵ��������꣬������
		if (top.first == x && top.second == y)
			return true;
		//����:��������
		for (int i = 0; i < 4; i++)
		{
			int nexti = i + map[i][0];
			int nextj = j + map[i][1];
			if (nexti < 0 || nexti >= row || nextj < 0 || nextj >= col)
				continue;
			//û���ϰ���û�з��ʹ��Ľڵ����
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
	cout << "�������Թ��Ĵ�С���к���" << endl;
	cin >> row >> col;
	vector<vector<int>> grid(row, vector<int>(col));
	cout << "�������Թ���Ԫ��" << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> grid[i][j];
		}
	}
	while (1)
	{
		cout << "�������Թ���ںͳ�������" << endl;
		cin >> i >> j >> x >> y;
		cout << "�Ƿ�����߳��Թ���" << BFS(grid, i, j, x, y) << endl;
	}
	return 0;
}