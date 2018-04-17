#include<iostream>
#include<bitset>
using namespace std;
int bitSwapRequired(int a, int b) {
	int result = a ^ b;
	int count = 0;
	for (int i = 0; i < 32; i++) {
		count += result & 0x01;
		result = result >> 1;
	}
	return count;
}
int main() {
	int a = -1;
	int b = 1;
	cout << bitSwapRequired(a, b) << endl;
	/*bitset<32> bs(result);
	cout << bs << " " << count << endl;*/
	system("pause");
	return 0;
}