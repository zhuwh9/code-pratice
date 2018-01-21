#include<iostream>
#include<string>
#include<vector>
using namespace std;
int strStr(const char *source, const char *target) {
	// write your code here
	if (source == NULL || target == NULL) {
		return -1;
	}
	int length_source = strlen(source);
	int length_target = strlen(target);
	if (length_target == 0) {
		return 0;
	}
	for (int i = 0; i < length_source; i++) {
		bool isDiff = false;
		for (int j = 0; j < length_target; j++) {
			if (j+i < length_source && source[j + i] != target[j]) {
				isDiff = true;
			}
			else if (j + i >= length_source && isDiff == false) {
				return -1;
			}
		}
		if (isDiff == false) {
			return i;
		}
	}
	return -1;
}
int main() {
	string source = "source";
	string target = "rced";
	cout << strStr(source.c_str(), target.c_str()) << endl;
	system("pause");
	return 0;
}