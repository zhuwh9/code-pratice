#include<iostream>
#include<string>
using namespace std;
int lengthOfLastWord(string &s) {
	int count = 0;
	string::iterator itr = --s.end();
	while (*itr == ' ') {
		itr = s.erase(itr);
		itr--;
	}
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] != ' ') {
			count++;
		}
		else {
			break;
		}
	}
	return count;
}