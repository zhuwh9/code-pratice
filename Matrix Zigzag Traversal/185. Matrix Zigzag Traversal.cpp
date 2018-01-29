#include<iostream>
#include<vector>
using namespace std;
vector<int> printZMatrix(vector<vector<int>> &matrix) {
	int row = matrix.size();
	int col = matrix[0].size();
	vector<int> result;
	int i = 0, j = 0;
	result.push_back(matrix[0][0]);
	while (result.size() < row * col) {
		while (i - 1 >= 0 && j + 1 < col) {
			result.push_back(matrix[--i][++j]);
		}
		if (j + 1 < col) {
			result.push_back(matrix[i][++j]);
		}
		else if (i + 1 < row) {
			result.push_back(matrix[++i][j]);
		}
		while (i + 1 < row && j - 1 >= 0) {
			result.push_back(matrix[++i][--j]);
		}
		if (i + 1 < row) {
			result.push_back(matrix[++i][j]);
		}
		else if (j + 1 < col) {
			result.push_back(matrix[i][++j]);
		}
	}
	return result;
}