#include<iostream>
#include<vector>
using namespace std;
int removeDuplicates(vector<int> &nums) {
	// write your code here
	if (nums.empty()) {
		return 0;
	}
	int count = 1;
	int current = nums[0];
	vector<int>::iterator itr = nums.begin();
	itr++;
	while (1) {
		if (itr == nums.end()) {
			break;
		}
		if (*itr == current) {
			if (count >= 2) {
				itr = nums.erase(itr);
			}
			else {
				count++;
				itr++;
			}
		}
		else {
			count = 1;
			current = *itr;
			itr++;
		}
	}
	return nums.size();
}
int main() {
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(3);
	nums.push_back(3);
	cout << removeDuplicates(nums) << endl;
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " " << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}