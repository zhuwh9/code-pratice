#include<iostream>
#include<vector>
#include<string>
using namespace std;
string addBinary(string &a, string &b) {
	vector<int> binary_a, binary_b, binary_result;
	for (int i = a.size() - 1; i >= 0; i--) {
		if (a[i] == '1') {
			binary_a.push_back(1);
		}
		else {
			binary_a.push_back(0);
		}
	}
	for (int i = b.size() - 1; i >= 0; i--) {
		if (b[i] == '1') {
			binary_b.push_back(1);
		}
		else {
			binary_b.push_back(0);
		}
	}
	int carrier = 0;
	int remainder = 0;
	int sum = 0;
	int i = 0;
	while (1) {
		if (i < binary_a.size() && i < binary_b.size()) {
			sum = binary_a[i] + binary_b[i] + carrier;
			remainder = sum % 2;
			carrier = sum / 2;
			binary_result.push_back(remainder);
		}
		else if (i < binary_a.size() && i >= binary_b.size()) {
			sum = binary_a[i] + carrier;
			remainder = sum % 2;
			carrier = sum / 2;
			binary_result.push_back(remainder);
		}
		else if (i >= binary_a.size() && i < binary_b.size()) {
			sum = binary_b[i] + carrier;
			remainder = sum % 2;
			carrier = sum / 2;
			binary_result.push_back(remainder);
		}
		else {
			break;
		}
		i++;
	}
	if (carrier != 0) {
		binary_result.push_back(carrier);
	}
	string result;
	while (binary_result.empty() == false) {
		if (binary_result.back() == 1) {
			result.push_back('1');
		}
		else if (binary_result.back() == 0) {
			result.push_back('0');
		}
		binary_result.pop_back();
	}
	return result;
}
int main() {
	string a = "11";
	string b = "1";
	cout << addBinary(a, b) << endl;
	system("pause");
	return 0;
}