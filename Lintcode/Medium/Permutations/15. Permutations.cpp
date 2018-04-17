#include<iostream>
#include<vector>
using namespace std;
void permuteHelper(const vector<int> &nums, bool * visited, vector<int> &path, vector<vector<int>> &paths) {
	if (path.size() == nums.size()) {
		paths.push_back(path);
		return;
	}
	for (int i = 0; i < nums.size(); i++) {
		if (visited[i] == false) {
			visited[i] = true;
			path.push_back(nums[i]);
			permuteHelper(nums, visited, path, paths);
			visited[i] = false;
			path.pop_back();
		}
	}
}
vector<vector<int>> permute(vector<int> &nums) {
	vector<vector<int>> paths;
	if (nums.empty()) {
		vector<int> t;
		paths.push_back(t);
		return paths;
	}
	bool * visited = new bool[nums.size()]();
	vector<int> path;
	permuteHelper(nums, visited, path, paths);
	return paths;
}