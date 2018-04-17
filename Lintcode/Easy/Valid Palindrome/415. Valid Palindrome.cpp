#include<iostream>
#include<string>
using namespace std;
bool isPalindrome(string &s) {
	string::iterator itr = s.begin();
	while (itr != s.end()) {
		if ('a' <= *itr && *itr <= 'z') {
			itr++;
		}
		else if ('A' <= *itr && *itr <= 'Z') {
			*itr = *itr + 'a' - 'A';
			itr++;
		}
		else if ('0' <= *itr && *itr <= '9') {
			itr++;
		}
		else {
			itr = s.erase(itr);
		}
	}
	for (int i = 0; i < s.size() / 2; i++) {
		if (s[i] != s[s.size() - 1 - i]) {
			return false;
		}
	}
	return true;
}
int main() {
	string a = "A man, a plan, a canal: Panama";
	string b = "race a car";
	string c = "1a2";
	cout << isPalindrome(c) << endl;
	cout << c << endl;
	cout << c.size() << endl;
	system("pause");
	return 0;
}