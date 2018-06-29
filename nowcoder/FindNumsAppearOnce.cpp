class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        map<int, int> m;
        for (int i = 0; i < data.size(); i++) {
            m[data[i]]++;
        }
        bool first = true;
        for (int i = 0; i < data.size(); i++) {
            if (m[data[i]] == 1 && first) {
                *num1 = data[i];
                first = false;
            } else if (m[data[i]] == 1 && !first && data[i] != *num1) {
                *num2 = data[i];
                return;
            }
        }
        return;
    }
};
