#include<iostream>
#include<vector>
using namespace std;
int removeDuplicates(vector<int> &nums) {
	// write your code here
	if (nums.empty()) {
		return 0;
	}
	int count = 0;;
	int current = nums[0];
	vector<int>::iterator itr = nums.begin();
	itr++;
	while (1) {
		if (itr == nums.end()) {
			break;
		}
		if (*itr == current) {
			itr = nums.erase(itr);
		}
		else {
			current = *itr;
			count++;
			itr++;
		}
	}
	return nums.size();
}
int main() {
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(3);
	nums.push_back(3);
	cout << removeDuplicates(nums) << endl;
	system("pause");
	return 0;
}