#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int hashCode(string &key, int HASH_SIZE) {
	long sum = (int)key[0];
	for (int i = 1; i < key.length(); i++) {
		sum = (sum * 33) % HASH_SIZE + (int)key[i];
	}
	return (int)(sum % HASH_SIZE);
}
int main() {
	string test = "Wrong answer or accepted?";
	cout << hashCode(test, 1000000007) << endl;
	system("pause");
	return 0;
}