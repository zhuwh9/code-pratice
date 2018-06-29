class Solution {
public:
    string ReverseSentence(string str) {
        string res = "";
        stack<char> s;
        for (int i = str.size()-1; i >= 0; i--) {
            if (str[i] != ' ') {
                s.push(str[i]);
            } else {
                while (!s.empty()) {
                    res += s.top();
                    s.pop();
                }
                res += str[i];
            }
        }
        while (!s.empty()) {
            res += s.top();
            s.pop();
        }
        return res;
    }
};
