/*
Solve the lake counting problem using dfs
*/
#include <iostream>
#include <cstdio>

using namespace std;

#define MAXN 1000
#define MAXM 1000

char field[MAXN][MAXM + 1];
int n, m;

//搜索函数，从有'W'的位置开始
void dfs(int x, int y)
{
	//将当前的位置置为'.'
	field[x][y] = '.';
	//八个方向逐次遍历，如果为'W'则置为'.'
	for (int dx = -1; dx <= 1; dx++) {
		for (int dy = -1; dy <= 1; dy++) {
			int nx = x + dx, ny = y + dy;
			if (0 <= nx && nx < n && 0 <= ny && ny < m && field[nx][ny] == 'W') dfs(nx, ny);
		}
	}
	return;
}

int solution_()
{
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dfs(i, j);
			res++;
		}
	}
	return res;
}