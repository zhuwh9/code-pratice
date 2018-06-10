class Solution {
public:
    void push(int value) {
        s.push_back(value);
    }
    void pop() {
        s.pop_back();
    }
    int top() {
        return s[s.size()-1];
    }
    int min() {
        int minNum = s[0];
        for (int i = 1; i < s.size(); i++) {
            if (s[i] < minNum) {
                minNum = s[i];
            }
        }
        return minNum;
    }
private:
    vector<int> s;
};
