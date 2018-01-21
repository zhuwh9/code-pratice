#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<sstream>
using namespace std;
string getString(int n) {
	string result;
	char arr[100];
	if (n % 3 != 0 && n % 5 == 0) {
		result = "buzz";
	}
	else if (n % 3 == 0 && n % 5 != 0) {
		result = "fizz";
	}
	else if (n % 3 == 0 && n % 5 == 0) {
		result = "fizz buzz";
	}
	else {
		stringstream ss;
		ss << n;
		result = ss.str();
	}
	return result;
}
vector<string> fizzBuzz(int n) {
	// write your code here
	vector<string> result;
	for (int i = 1; i <= n; i++) {
		result.push_back(getString(i));
	}
	return result;
}
int main() {
	vector<string> result;
	result = fizzBuzz(15);
	for (int i = 0; i < result.size(); i++) {
		cout << "\"" << result.at(i) << "\", ";
		if ((i + 1) % 3 == 0) {
			cout << endl;
		}
	}
	cout << endl;
	system("pause");
	return 0;
}
