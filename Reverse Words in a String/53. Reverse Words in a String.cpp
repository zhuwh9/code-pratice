#include<iostream>
#include<string>
#include<vector>
using namespace std;
string reverseWords(string &s) {
	// write your code here
	string result = "";
	while (s.empty() == false && s.front() == ' ') {
		s.erase(s.begin());
	}
	while (s.empty() == false && s.back() == ' ') {
		s.erase(--s.end());
	}
	while (s.empty() == false) {
		string temp;
		while (s.empty() == false && s.back() != ' ') {
			temp.push_back(s.back());
			s.pop_back();
		}
		int space_count = 0;
		while (s.empty() == false && s.back() == ' ') {
			space_count++;
			s.pop_back();
		}
		while (temp.empty() == false) {
			result.push_back(temp.back());
			temp.pop_back();
		}
		if (space_count > 0) {
			result.push_back(' ');
		}
	}
	return result;
}
int main() {
	string s = "    the sky is blue   ";
	cout << reverseWords(s) << endl;
	system("pause");
	return 0;
}