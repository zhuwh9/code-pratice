#include<iostream>
#include<vector>
using namespace std;
int majorityNumber(vector<int> &nums) {
	// write your code here
	int plan = 0;
	int vote = 1;
	for (int i = 1; i <= nums.size() - 1; i++) {
		if (nums[plan] == nums[i]) {
			vote++;
		}
		else {
			vote--;
		}
		if (vote == 0) {
			plan = i;
			vote = 1;
		}
	}
	return nums[plan];
}
int main() {
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(2);
	cout << majorityNumber(nums) << endl;
	system("pause");
	return 0;
}