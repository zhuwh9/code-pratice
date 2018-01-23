#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int singleNumber(vector<int> &nums) {
	// write your code here
	unordered_map<int, int> num_map;
	for (int i = 0; i < nums.size(); i++) {
		if (num_map[nums[i]] == 0) {
			num_map[nums[i]]++;
		}
		else {
			num_map[nums[i]]--;
			if (num_map[nums[i]] == 0) {
				num_map.erase(nums[i]);
			}
		}
	}
	return num_map.begin()->first;
}
//int main() {
//	vector<int> nums;
//	nums.push_back(1);
//	nums.push_back(1);
//	nums.push_back(2);
//	nums.push_back(3);
//	nums.push_back(3);
//	cout << singleNumber(nums) << endl;
//	system("pause");
//	return 0;
//}