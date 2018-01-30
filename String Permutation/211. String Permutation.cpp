#include<iostream>
using namespace std;
void quickSort(string& str, int left, int right) {
	if (left < right) {
		char pivot = str[left];
		int i = left + 1;
		int j = right;
		while (i <= j) {
			while (i <= j && str[i] <= pivot) {
				i++;
			}
			while (i <= j && str[j] > pivot) {
				j--;
			}
			if (i <= j) {
				char temp = str[i];
				str[i] = str[j];
				str[j] = temp;
				i++;
				j--;
			}
		}
		char temp = str[left];
		str[left] = str[j];
		str[j] = temp;
		quickSort(str, left, j - 1);
		quickSort(str, j + 1, right);
	}
}
bool Permutation(string &A, string &B) {
	if (A.size() != B.size()) {
		return false;
	}
	else {
		quickSort(A, 0, A.size() - 1);
		quickSort(B, 0, B.size() - 1);
		for (int i = 0; i < A.size(); i++) {
			if (A[i] != B[i]) {
				return false;
			}
		}
		return true;
	}
}