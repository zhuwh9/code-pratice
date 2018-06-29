class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> res;
        int curMulRes = INT_MAX;
        int sm = 0, lg = 0;
        vector<int>::iterator itr = array.begin();
        for (; itr != array.end(); itr++) {
            vector<int>::iterator t = find(itr, array.end(), sum - *itr);
            if (t != itr && t != array.end()) {
                int first = *itr;
                int second = *t;
                if (first * second < curMulRes) {
                    curMulRes = first * second;
                    sm = first > second ? second : first;
                    lg = first > second ? first : second;
                }
            }
        }
        if (sm != lg) {
            res.push_back(sm);
            res.push_back(lg);
        }
        return res;
    }
};
