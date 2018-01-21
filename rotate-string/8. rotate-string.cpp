#include<iostream>
#include<string>
#include<list>
#include<string.h>
using namespace std;
void rotateString(string &str, int offset) {
	if (str.empty()) {
		return;
	}
	offset = offset % str.size();//reduce unnecessary loop
	// write your code here
	list<char> result;
	for (int i = 0; i < str.size(); i++) {
		result.push_back(str.at(i));
	}
	for (int i = 0; i < offset; i++) {
		char back = result.back();
		result.pop_back();
		result.push_front(back);
	}
	str.clear();
	int size = result.size();
	for (int i = 0; i < size; i++) {
		str.push_back(result.front());
		result.pop_front();
	}
}
int main() {
	string test = "abcdefg";
	int offset = 3;
	rotateString(test, offset);
	cout << test << endl;
	system("pause");
	return 0;
}