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
bool isUnique(string &str) {
	string temp = str;
	quickSort(temp, 0, str.size()-1);
	for (int i = 0; i < temp.size() - 1; i++) {
		if (temp[i] == temp[i + 1]) {
			return false;
		}
	}
	return true;
}
int main() {
	string str = "acbb";
	quickSort(str, 0, 3);
	cout << str << endl;
	system("pause");
	return 0;
}