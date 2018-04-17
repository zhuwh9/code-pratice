#include<iostream>
#include<string>
#include<vector>
using namespace std;
void printPath(vector<vector<bool>> &path) {
	for (int i = 0; i < path.size(); i++) {
		for (int j = 0; j < path[0].size(); j++) {
			cout << path[j][i] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
bool isInterleave(string &s1, string &s2, string &s3) {
	int m = s1.length();
	int n = s2.length();
	if (m + n != s3.length()) {
		return false;
	}
	else if (m == 0 && n != 0) {
		for (int i = 0; i < n; i++) {
			if (s2[i] != s3[i]) {
				return false;
			}
		}
		return true;
	}
	else if (m != 0 && n == 0) {
		for (int i = 0; i < m; i++) {
			if (s1[i] != s3[i]) {
				return false;
			}
		}
		return true;
	}
	else if (m == 0 && n == 0) {
		return true;
	}
	// dynamic programming
	vector<vector<bool>> path(m + 1, vector<bool>(n + 1, false));
	for (int i = 0; i < m + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			if (i == 0 && j == 0) {
				path[i][j] = true;
			}
			else if (i == 0) {
				path[i][j] = path[i][j - 1] && (s2[j - 1] == s3[j - 1]);
			}
			else if (j == 0) {
				path[i][j] = path[i - 1][j] && (s1[i - 1] == s3[i - 1]);
			}
			else {
				path[i][j] = (path[i][j - 1] && (s2[j - 1] == s3[i + j - 1])) || (path[i - 1][j] && (s1[i - 1] == s3[i + j - 1]));
			}
			printPath(path);
		}
	}
	return path[m][n];
}
int main() {
	string s1, s2, s3;
	s1 = "abbcddef";
	s2 = "accbbbcd";
	s3 = "abbcddefaccbbbdc";
	cout << isInterleave(s1, s2, s3) << endl;
	system("pause");
	return 0;
}