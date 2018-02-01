#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
// recursive way, too slow
//int minRecursive(vector<vector<int>> &grid, int i, int j) {
//	if (i == 0 && j == 0) {
//		return grid[0][0];
//	}
//	if (i == -1 || j == -1) {//ignore out-of-bound way
//		return INT_MAX;
//	}
//	return min(minRecursive(grid, i - 1, j), minRecursive(grid, i, j - 1)) + grid[i][j];
//}
//int minPathSum(vector<vector<int>> &grid) {
//	return minRecursive(grid, grid.size() - 1, grid[grid.size() - 1].size() - 1);
//}
int minPathSum(vector<vector<int>> &grid) {
	int row = grid.size();
	if (row == 0)
		return 0;
	int col = grid[0].size();
	vector<int> lastStatus(col+1, INT_MAX);
	lastStatus[1] = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			lastStatus[j + 1] = grid[i][j] + min(lastStatus[j], lastStatus[j + 1]);
		}
	}
	return lastStatus[col];
}
int main() {
	vector<vector<int>> grid;
	vector<int> t1, t2;
	t1.push_back(1);
	t1.push_back(2);
	t2.push_back(1);
	t2.push_back(1);
	grid.push_back(t1);
	grid.push_back(t2);
	cout << minPathSum(grid) << endl;
}