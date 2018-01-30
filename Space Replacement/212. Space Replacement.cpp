#include<iostream>
using namespace std;
int replaceBlank(char string[], int length) {
	if (length == 0 || string == NULL) {
		return NULL;
	}
	int len = strlen(string);
	int space_count = 0;
	for (int i = 0; i < len; i++) {
		if (string[i] == ' ') {
			space_count++;
		}
	}
	int j = len + space_count * 2;
	string[j] = '\0';
	j--;
	for (int i = len - 1; i >= 0; i--) {
		if (string[i] != ' ') {
			string[j] = string[i];
			j--;
		}
		else {
			// %20
			string[j] = '0';
			j--;
			string[j] = '2';
			j--;
			string[j] = '%';
			j--;
		}
	}
	return len + space_count * 2;
}
int main() {
	//Mr John Smith
	char string[30] = { 'M','r',' ','J','o','h', 'n', ' ','S','m','i','t','h' ,'\0'};
	cout << replaceBlank(string, 13) << endl;
	system("pause");
	return 0;
}