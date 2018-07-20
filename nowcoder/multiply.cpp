class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int size = A.size();
        vector<int> t;
        if (size == 0)
            return t;
        t.push_back(1);
        for (int i = 0; i < size - 1; i++)
            t.push_back(t.back()*A[i]);
        int temp = 1;
        for (int i = size - 1; i >= 0; i--) {
            t[i] = t[i] * temp;
            temp = temp * A[i];
        }
        return t;
    }
};
