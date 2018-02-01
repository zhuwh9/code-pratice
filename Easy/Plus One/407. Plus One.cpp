#include<iostream>
#include<vector>
using namespace std;
vector<int> plusOne(vector<int> &digits) {
	vector<int> reverse_digits;
	int len = digits.size();
	for (int i = 0; i < len; i++) {
		reverse_digits.push_back(digits.back());
		digits.pop_back();
	}
	int carrier = 0;
	int sum = 0;
	reverse_digits[0] += 1;
	for (int i = 0; i < len; i++) {
		sum = reverse_digits[i] + carrier;
		reverse_digits[i] = sum % 10;
		carrier = sum / 10;
	}
	if (carrier != 0) {
		reverse_digits.push_back(carrier);
	}
	digits.clear();
	len = reverse_digits.size();
	for (int i = 0; i < len; i++) {
		digits.push_back(reverse_digits.back());
		reverse_digits.pop_back();
	}
	return digits;
}
int main() {
	vector<int> digits;
	digits.push_back(9);
	digits.push_back(9);
	digits.push_back(9);
	vector<int> result = plusOne(digits);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i];
	}
	cout << endl;
	system("pause");
	return 0;
}