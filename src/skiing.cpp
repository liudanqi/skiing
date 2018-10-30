#include "skiing.h"
#include <iostream>
#include <queue>
using namespace std;
const int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };  //œ¬”“…œ◊Û“∆∂Ø
void Skiing::initializer() {
	cout << "R:";cin >> R;
	cout << "C:";cin >> C;
	for (int i = 1;i <=R;i++) {
		for (int j = 1;j <=C;j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1;i <= R;i++) {
		for (int j = 1;j <= C;j++)
			dp[i][j] = 0;
	}
}
int Skiing::compute_longest_path_by_dfs(int x, int y) {
	if (dp[x][y])return dp[x][y];
	int max = 1;
	for (int z = 0;z < 4;z++) {
		int xx = x + dir[z][0];
		int yy = y + dir[z][1];
		if (map[x][y] > map[xx][yy]&&xx>=1&&xx<=R&&yy>=1&&yy<=C){
			int len = compute_longest_path_by_dfs(xx, yy)+1;
			if (max < len) {
				max = len;
			}
	}
	}
	return dp[x][y] = max;
}
int Skiing::get_dp() {
	int temp=0;
	for (int i = 1;i <= R;i++) {
		for (int j = 1;j <= C;j++) {
			dp[i][j] = compute_longest_path_by_dfs(i, j);
			if (dp[i][j] > temp)temp = dp[i][j];
			dp[i][j] = 0;//clear dp_
		}
	}
	cout << temp << endl;
	return temp;
}
void Skiing::compute_longest_path_by_bfs(int x, int y) {
	for (int i = 1;i <=R;i++) {
		for (int j = 1;j <=C;j++) {
			backPathBFS[i][j].row = 0;
			backPathBFS[i][j].col = 0;
		}
	}
	queue<Pos>Queue;
	Pos cur;cur.row = x;cur.col = y;
	while (!Queue.empty()) {
		Queue.pop();
	}
	Queue.push(cur);
	dp[x][y] = 1;
	while (!Queue.empty()) {
		Pos cur = Queue.front();
		Queue.pop();
		if (cur.row <1||cur.row>R||cur.col<1||cur.col>C) {
			BackTrackPath();
			return;
		}
		// find the adjacent
		for (int z = 0;z < 4;z++) {
			Pos next;
			next.row = cur.row + dir[z][0];
			next.col = cur.col + dir[z][1];
			if (cur.row >=1&&cur.row<=R&&cur.col>=1&&cur.col<=C&&dp[next.row][next.col] == 0) {
				dp[next.row][next.col] = 1;
				backPathBFS[next.row][next.col].row = cur.row;
				backPathBFS[next.row][next.col].col = cur.col;
				Queue.push(next);
			}
		}
	}
}
int Skiing::BackTrackPath() {
		int temp = 0;
		for (int i = 1;i <= R;i++) {
			for (int j = 1;j <= C;j++) {
				compute_longest_path_by_bfs(i, j);
				if (dp[i][j]!=0)temp++;
				dp[i][j] = 0;//clear dp_
			}
		}
		return temp;
}
