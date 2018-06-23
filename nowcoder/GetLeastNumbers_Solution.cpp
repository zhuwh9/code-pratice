class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if (input.size() == 0) return res;
        if (input.size() < k) return res;
        sort(input.begin(), input.end());
        for (int i = 0; i < k; i++) {
            res.push_back(input[i]);
        }
        return res;
    }
};
