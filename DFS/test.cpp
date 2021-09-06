#include<iostream>
#include<vector>
using namespace std;

void DFS(vector<int> box, vector<int> used, int idx)
{
	//�߽�
	if (idx == box.size())
	{
		for (int i = 1; i < box.size(); i++)
		{
			cout << box[i] << " ";
		}
		cout << endl;
		return;
	}
	//����ǰ����
	for (int i = 1; i < box.size(); i++)
	{
		//�жϵ�ǰ���Ƿ��ù�
		if (used[i] == 0)
		{
			//��ǰû��ʹ�õ��ƷŽ�����
			box[idx] = i;
			used[i] = 1;

			//������һ������
			DFS(box, used, idx + 1);
			//���յ�ǰʹ�õ���
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