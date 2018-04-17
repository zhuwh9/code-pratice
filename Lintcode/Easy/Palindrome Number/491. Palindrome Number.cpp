#include<iostream>
#include<vector>
using namespace std;
bool isPalindrome(int num) {
	vector<int> palindrome;
	while (num != 0) {
		palindrome.push_back(num % 10);
		num /= 10;
	}
	for (int i = 0; i < palindrome.size() / 2; i++) {
		if (palindrome[i] != palindrome[palindrome.size() - 1 - i]) {
			return false;
		}
	}
	return true;
}
int main() {
	int num = 1232;
	cout << isPalindrome(num) << endl;
	system("pause");
	return 0;
}