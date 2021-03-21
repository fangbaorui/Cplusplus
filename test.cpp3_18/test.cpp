#define _CRT_SECURE_NO_WARNINGS
//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h> //
using namespace std;
typedef long long ll;

const int maxn = 10;
const int N = 6; //

int Cn4[15] = { 0,1,5,15,35,70,126,210,330,495,715,1001 };
int fib[15] = { 1,1,2,3,5,8,13,21,34,55,89,144 };

int a[maxn][maxn]; //
bool use[maxn][maxn]; //
int score = 0;
int t = 36;

void inni(int x) {
	memset(use, 0, sizeof(use));
	if (x == 1) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				a[i][j] = i * j;
			}
		}
	}
	else if (x == 2) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				a[i][j] = Cn4[i + j - 1];
			}
		}
	}
	else if (x == 3) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				a[i][j] = fib[i + j - 1];
			}
		}
	}
	return;
}

void show() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!use[i][j]) {
				cout << "    *";
			}
			else {
				printf("%5d", a[i][j]);
			}
		}
		cout << endl;
	}
	cout << "当前分数：" << score << endl;
	return;
}

bool judgeNum(string str) {

	int len = str.size(); // 长度

	for (int i = 0; i < len; i++) {
		if (str[0] < '0' || str[0] > '9') {
			return false; // 
		}
	}

	return true;
}

bool judgeNumRange(int x) {
	if (x >= 1 && x <= N) {
		return true; // 合法
	}
	return false;
}

int change(string str) {
	int len = str.size(); // 长度
	int ans = 0;

	for (int i = 0; i < len; i++) {
		ans = ans * 10 + (str[i] - '0');
	}

	return ans;
}

void guess() {
	string s[5];
	int x, y, z;

	cout << "请输入坐标x,y（1 <= x,y <= " << N << "）,猜测值z" << endl;

	// 输入合法性判断1，防止非法字符
	cin >> s[1] >> s[2] >> s[3];
	if (!(judgeNum(s[1]) && judgeNum(s[2]) && judgeNum(s[3]))) {
		cout << "非法输入！" << endl;
		return;
	}

	x = change(s[1]);
	y = change(s[2]);
	z = change(s[3]);

	// 输入合法性判断2，防止a数组越界
	if (!(judgeNumRange(x) && judgeNumRange(y))) {
		cout << "非法输入！" << endl;
		return;
	}

	if (a[y][x] == z) {
		if (use[y][x]) { // 已经猜对过
			cout << "你已经猜对过啦，换个数字猜叭~~" << endl;
		}
		else {
			cout << "猜对啦！！" << endl;
			use[y][x] = true;
			score += 10;
			t--;
		}
	}
	else {
		cout << "猜错啦~~~" << endl;
		score -= 5;
	}
	return;
}

int main() { // 
	int k = 1;

	while (k <= 3) {
		inni(k);

		while (t) {
			show();
			guess();
		}
		cout << "第" << k << "轮猜数结束~~ 你的当前得分为：" << score << "分！" << endl;
		system("pause"); //

		k++;
		t = 36; //
	}

	cout << "游戏结束~~ 你的最终得分为：" << score << "分！" << endl;

	getchar(); getchar();
	return 0;
}
