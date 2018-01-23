#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
bool compareStrings(string &A, string &B) {
	// write your code here
	vector<int> map_A(26,0);
	vector<int> map_B(26,0);
	for (int i = 0; i < A.size(); i++) {
		int index = A[i] - 'A';
		map_A[index]++;
	}
	for (int i = 0; i < B.size(); i++) {
		int index = B[i] - 'A';
		map_B[index]++;
	}
	for (int i = 0; i < 26; i++) {
		if (map_A[i] == 0 && map_B[i] == 0) {
			continue;
		}
		else {
			if (map_A[i] < map_B[i]) {
				return false;
			}
		}
	}
	return true;
}
int main() {
	string A = "ABCD";
	string B = "AACD";
	cout << compareStrings(A, B) << endl;
	system("pause");
	return 0;
}
