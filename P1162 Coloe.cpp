/*
洛谷P1162 涂色问题
@author: soert2003
*/
#include <iostream>

using namespace std;

int maze[32][32];//记录数字的数组
char flag[32][32];//决定是否涂色的数组

//移动向量
int dp[4] = { 1,0,-1,0 }, dq[4] = { 0,1,0,-1 };

int n;

//深度优先搜索函数
//在n*n的矩阵上外加一圈0
void dfs(int p, int q)
{
	//由于外加了一圈零，所以原本n*n的矩阵变成了(n+2)*(n+2)的矩阵，相应的边界要发生变化
	//如果越界了，或者遍历到了1所在的方格，则返回
	if (p<0 || p>n + 1 || q<0 || q>n + 1 || flag[p][q] != 'o') return;
	//涂色
	flag[p][q] = 'x';
	//四个方向逐次遍历
	for (int i = 0; i < 4; i++)
		dfs(p + dp[i], q + dq[i]);
}

int main(void)
{
	cin >> n;
	//输入
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> maze[i][j];
			if (maze[i][j] == 0) flag[i][j] = 'o';
			else flag[i][j] = 'l';
		}
	}
	//对maze的第一行进行0赋值
	for (int i = 0; i < n + 2; i++) flag[0][i] = 'o';
	for (int i = 0; i < n + 2; i++) flag[n + 1][i] = 'o';
	for (int i = 1; i <= n; i++) flag[i][0] = 'o', flag[i][n + 1] = 'o';
	
	dfs(0, 0);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (flag[i][j] == 'o')	cout << 2 << " ";
			else cout << maze[i][j] << " ";
		}
		cout << endl;
	}
}