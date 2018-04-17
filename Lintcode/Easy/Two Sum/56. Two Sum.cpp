#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
vector<int> twoSum(vector<int> &numbers, int target) {
	// write your code here
	unordered_map<int, int> num_map;
	for (int i = 0; i < numbers.size(); i++) {
		num_map[numbers[i]] = i;
	}
	for (int i = 0; i < numbers.size(); i++) {
		int diff = target - numbers[i];
		if (num_map.count(diff) && num_map.at(diff) != i) {
			int index = num_map.at(diff);
			vector<int> result;
			if (i > index) {
				result.push_back(index);
				result.push_back(i);
			}
			else {
				result.push_back(i);
				result.push_back(index);
			}
			return result;
		}
	}
}