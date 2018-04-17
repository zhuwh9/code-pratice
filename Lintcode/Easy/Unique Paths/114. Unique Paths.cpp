#include<iostream>
using namespace std;
// iteration way: dynamic programming, 2-d matrix
int uniquePaths(int m, int n) {
	int** path = new int*[m];
	for (int i = 0; i < m; i++) {
		path[i] = new int[n];
		path[i][0] = 1;
	}
	for (int i = 0; i < n; i++) {
		path[0][i] = 1;
	}
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			path[i][j] = path[i - 1][j] + path[i][j - 1];
		}
	}
	return path[m - 1][n - 1];
}
// iteration way: dynamic programming, 1-d vector
int uniquePaths(int m, int n) {
	int* path = new int[n];
	for (int i = 0; i < n; i++) {
		path[i] = 1;
	}
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			path[j] = path[j] + path[j-1];
		}
	}
	return path[n-1];
}

// recursive way, too slow
int uniquePaths(int m, int n) {
	if (m == 1 || n == 1) {
		return 1;
	}
	else {
		return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
	}
}

// iteration way: combination(factorial)
// disadvantage: when factorial is large, accuracy will lose
double combination(int start, int end) {
	double sum = 1;
	for (int i = start; i <= end; i++) {
		sum *= i;
	}
	return sum;
}
int uniquePaths(int m, int n) {
	double temp = combination(n, m+n-2);
	double temp1 = combination(1, m - 1);
	temp /= temp1;
	return (int)temp;
}