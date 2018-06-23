class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int halfSize = numbers.size() / 2;
        unordered_map<int,int> ma;
        for (int i = 0; i < numbers.size(); i++) {
            ma[numbers[i]] = ma[numbers[i]] + 1;
        }
        for (unordered_map<int,int>::iterator itr = ma.begin(); itr != ma.end(); itr++) {
            if (itr->second > halfSize) {
                return itr->first;
            }
        }
        return 0;
    }
};
