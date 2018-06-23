class Solution {
public:
    void swap(string &str, int i, int j) {
        char t = str[i];
        str[i] = str[j];
        str[j] = t;
    }
    void PermutationHelper(vector<string> &res, string str, int index) {
        if (index == str.size() - 1)
            res.push_back(str);
        for (int i = index; i < str.size(); i++) {
            if (i != index && str[i] == str[index]) {
                continue;
            }
            swap(str, i, index);
            PermutationHelper(res, str, index+1);
            swap(str, i, index);
        }
    }
    vector<string> Permutation(string str) {
        vector<string> res;
        if (str.size() == 0) return res;
        PermutationHelper(res, str, 0);
        sort(res.begin(), res.end());
        return res;
    }
};
