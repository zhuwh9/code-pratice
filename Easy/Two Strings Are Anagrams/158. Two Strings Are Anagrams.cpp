#include<iostream>
#include<string>
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
bool anagram(string s, string t) {
	if (s.size() != t.size()) {
		return false;
	}
	quickSort(s, 0, s.size() - 1);
	quickSort(t, 0, t.size() - 1);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != t[i]) {
			return false;
		}
	}
	return true;
}