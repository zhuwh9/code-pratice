#include<iostream>
#include<vector>
using namespace std;
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	int** path = new int*[m];
	for (int i = 0; i < m; i++) {
		path[i] = new int[n];
	}
	for (int i = 0; i < m; i++) {
		if (obstacleGrid[i][0] == 1) {
			for (int j = i; j < m; j++) {
				path[j][0] = 0;
			}
			break;
		}
		else {
			path[i][0] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		if (obstacleGrid[0][i] == 1) {
			path[0][i] = 0;
			for (int j = i; j < n; j++) {
				path[0][j] = 0;
			}
			break;
		}
		else {
			path[0][i] = 1;
		}
	}
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			if (obstacleGrid[i][j] == 1) {
				path[i][j] = 0;
			}
			else {
				path[i][j] = path[i - 1][j] + path[i][j - 1];
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << path[i][j] << " ";
		}
		cout << endl;
	}
	return path[m - 1][n - 1];
}
//int main() {
//	vector<vector<int>> grid;
//	vector<int> temp;temp.push_back(0);temp.push_back(0);
//	grid.push_back(temp);
//	temp.clear();temp.push_back(0);temp.push_back(0);
//	grid.push_back(temp);
//	temp.clear();temp.push_back(0);temp.push_back(0);
//	grid.push_back(temp);
//	temp.clear();temp.push_back(1);temp.push_back(0);
//	grid.push_back(temp);
//	temp.clear();temp.push_back(0);temp.push_back(0);
//	grid.push_back(temp);
//	cout << uniquePathsWithObstacles(grid) << endl;
//	system("pause");
//	return 0;
//}