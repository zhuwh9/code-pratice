class Solution {
public:
    vector<int> GenerateSequence(int start, int sum) {
        vector<int> res;
        int curSum = 0;
        while (curSum < sum) {
            curSum += start;
            res.push_back(start);
            start++;
        }
        if (curSum == sum) {
            return res;
        } else {
            vector<int> empty;
            return empty;
        }
    }
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector< vector<int> > res;
        for (int i = 1; i <= sum / 2 + 1; i++) {
            vector<int> t = GenerateSequence(i, sum);
            if (t.size() >= 2) {
                res.push_back(t);
            }
        }
        return res;
    }
};
