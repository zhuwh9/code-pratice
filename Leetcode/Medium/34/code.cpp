#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> result;
    bool isFound = false;
    int begin = 0;
    int end = nums.size() - 1;
	if (begin == end) {
		if (nums[begin] == target) {
			result.push_back(begin);
			result.push_back(end);
			return result;
		}
	}
    while (begin < end) {
        int mid = begin + (end - begin) / 2;
        if (nums[mid] > target) {
            end = mid - 1;
        } else if (nums[mid] < target) {
            begin = mid + 1;
        } else {
            end = mid;
			isFound = true;
        }
        if (begin + 1 == end || begin == end) {
            if (nums[begin] == target || nums[end] == target) {
                isFound = true;
            }
            break;
        }
    }
    if (isFound == false) {
        result.push_back(-1);
        result.push_back(-1);
        return result;
    } else {
        if (nums[begin] == target) {
            result.push_back(begin);
        } else {
            result.push_back(end);
        }
    }
    begin = 0;
    end = nums.size() - 1;
    while (begin < end) {
        int mid = begin + (end - begin) / 2;
        if (nums[mid] > target) {
            end = mid - 1;
        } else if (nums[mid] < target) {
            begin = mid + 1;
        } else {
            begin = mid;
            isFound = true;
        }
        if (begin + 1 == end || begin == end) {
            if (nums[begin] == target || nums[end] == target) {
                isFound = true;
            }
            break;
        }
    }
    if (nums[end] == target) {
        result.push_back(end);
    } else {
        result.push_back(begin);
    }
    return result;
}

int main() {
    vector<int> input;
    input.push_back(5);
    input.push_back(7);
    // input.push_back(7);
    // input.push_back(8);
    // input.push_back(8);
    // input.push_back(10);
    vector<int> output = searchRange(input, 7);
    cout << "[" << output[0] << "," << output[1] << "]" << endl;
    return 0;
}