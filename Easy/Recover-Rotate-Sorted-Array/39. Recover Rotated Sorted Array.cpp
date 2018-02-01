#include<iostream>
#include<vector>
using namespace std;
void recoverRotatedSortedArray(vector<int> &nums) {
	// too easy
	while (1) {
		int front = nums.front();
		int back = nums.back();
		if (front >= back) {
			nums.erase(nums.begin());
			nums.push_back(front);
		}
		else {
			break;
		}
	}
}