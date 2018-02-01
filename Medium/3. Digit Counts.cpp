#include<iostream>
using namespace std;
int countK(int k, int n) {
	int count = 0;
	if (k == 0 && n == 0) {
		count++;
	}
	int remainder = 0;
	while (n != 0) {
		remainder = n % 10;
		if (remainder == k) {
			count++;
		}
		n /= 10;
	}
	return count;
}
int digitCounts(int k, int n) {
	int num_k = 0;
	for (int i = 0; i <= n; i++) {
		num_k += countK(k, i);
	}
	return num_k;
}
int main() {
	int n = 19;
	int k = 0;
	cout << digitCounts(k, n) << endl;
	system("pause");
	return 0;
}