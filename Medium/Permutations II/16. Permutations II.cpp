#include<iostream>
#include<set>
#include<vector>
using namespace std;
void swap(vector<int> &nums, int index1, int index2) {
	int temp = nums[index1];
	nums[index1] = nums[index2];
	nums[index2] = temp;
}
void permute(vector<int> &nums, int start, set<vector<int>> &res) {
	if (start >= nums.size()) {
		res.insert(nums);
	}
	for (int i = start; i < nums.size(); ++i) {
		if (i != start && nums[i] == nums[start]) {
			continue;
		}
		swap(nums, i, start);
		permute(nums, start + 1, res);
		swap(nums, i, start);
	}
}
vector<vector<int>> permuteUnique(vector<int> &nums) {
	set<vector<int>> res;
	permute(nums, 0, res);
	return vector<vector<int>>(res.begin(), res.end());
}
