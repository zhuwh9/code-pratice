#include<iostream>
#include<vector>
using namespace std;
int numIslands(vector<vector<bool>> &grid) {
	int row = grid.size();
	if (row == 0) {
		return 0;
	}
	int col = grid[0].size();
	if (col == 0) {
		return 0;
	}
	int count = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (grid[i][j] != true)
				continue;
			count++;
			dfs(grid, i, j);
		}
	}
	return count;
}
void dfs(vector<vector<bool>> &grid, int i, int j) {
	int row = grid.size();
	int col = grid[0].size();
	if (i < 0 || i >= row || j < 0 || j >= col) {
		return;
	}
	if (grid[i][j] == true) {
		grid[i][j] = false;
		dfs(grid, i - 1, j);
		dfs(grid, i + 1, j);
		dfs(grid, i, j - 1);
		dfs(grid, i, j + 1);
	}
}
int main() {
	system("pause");
	return 0;
}