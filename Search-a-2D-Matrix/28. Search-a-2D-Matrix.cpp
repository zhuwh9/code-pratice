#include<iostream>
#include<vector>
using namespace std;
// this way runs slower
bool searchMatrix(vector<vector<int>> &matrix, int target) {
	// write your code here
	int pos_row = -1;
	for (int i = 0; i < matrix.size(); i++) {
		int first = matrix.at(i).front();
		int last = matrix.at(i).back();
		if (first <= target && last >= target) {
			pos_row = i;
			break;
		}
	}
	if (pos_row == -1) {
		return false;
	}
	for (int i = 0; i < matrix.at(pos_row).size(); i++) {
		if (matrix.at(pos_row).at(i) == target) {
			return true;
		}
	}
	return false;
}
// this way has a limit that 
// each row vector has to be the same size
bool searchMatrix(vector<vector<int>> &matrix, int target) {
	// write your code here
	if (matrix.empty()) {
		return false;
	}
	// binary search once
	int row = matrix.size();
	int col = matrix.at(0).size();
	int start = 0;
	int end = row * col - 1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		int number = matrix[mid / col][mid % col];
		if (number == target) {
			return true;
		}
		else if (number < target) {
			start = mid + 1;
		}
		else if (number > target) {
			end = mid - 1;
		}
	}
	return false;
}
int main() {
	vector<vector<int>> matrix;
	vector<int> t;
	t.push_back(1);t.push_back(3);t.push_back(5);t.push_back(7);
	matrix.push_back(t);
	t.push_back(10);t.push_back(11);t.push_back(16);t.push_back(20);
	matrix.push_back(t);
	t.push_back(23);t.push_back(30);t.push_back(34);t.push_back(50);
	matrix.push_back(t);
	cout << searchMatrix(matrix, 3) << endl;
	cout << searchMatrix(matrix, 4) << endl;
	cout << searchMatrix(matrix, 5) << endl;
	system("pause");
	return 0;
}