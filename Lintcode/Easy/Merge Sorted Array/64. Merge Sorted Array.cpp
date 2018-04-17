#include<iostream>
#include<list>
using namespace std;
/*
* @param A: sorted integer array A which has m elements, but size of A is m+n
* @param m: An integer
* @param B: sorted integer array B which has n elements
* @param n: An integer
* @return: nothing
*/
void mergeSortedArray(int A[], int m, int B[], int n) {
	// write your code here
	list<int> temp;
	for (int i = 0; i < m; i++) {
		temp.push_back(A[i]);
	}
	if (n == 0) {
		return;
	}
	if (m == n) {
		for (int i = 0; i < m; i++) {
			A[i] = B[i];
		}
		return;
	}
	// A and B both have elements
	list<int>::iterator itr_current = temp.begin();
	list<int>::iterator itr_last = --temp.end();
	int pos = 0;
	while (1) {
		if (itr_current != itr_last) {
			int current = *itr_current;
			itr_current++;
			int next = *itr_current;
			if (current <= B[pos] && B[pos] <= next) {
				itr_current = temp.insert(itr_current, B[pos]);
				pos++;
				if (pos >= n) {
					break;
				}
			}
			else if (B[pos] <= current) {
				itr_current--;
				itr_current = temp.insert(itr_current, B[pos]);
				pos++;
				if (pos >= n) {
					break;
				}
			}
		}
		else {
			while (pos < n) {
				temp.insert(temp.end(), B[pos]);
				pos++;
			}
			break;
		}
	}
	pos = 0;
	for (itr_current = temp.begin(); itr_current != temp.end(); itr_current++) {
		A[pos] = *itr_current;
		pos++;
	}
}
int main() {
	int* A = new int[5];
	A[0] = 3;
	A[1] = 4;
	A[2] = 5;
	int* B = new int[2];
	B[0] = 1;
	B[1] = 2;
	mergeSortedArray(A, 3, B, 2);
	for (int i = 0; i < 5; i++) {
		cout << A[i] << " " << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}