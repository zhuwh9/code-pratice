class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if (array.size() == 0) return 0;
        int sum = array[0], curMax = array[0];
        for (int i = 1; i < array.size(); i++) {
            sum = array[i] > sum + array[i] ? array[i] : sum + array[i];
            curMax = sum > curMax ? sum : curMax;
        }
        return curMax;
    }
};
