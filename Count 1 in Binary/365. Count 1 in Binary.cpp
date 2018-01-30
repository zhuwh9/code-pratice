#include<iostream>
using namespace std;
int countOnes(int num) {
	int count = 0;
	for (int i = 0; i < 32; i++) {
		count += num & 0x01;
		num = num >> 1;
	}
	return count;
}