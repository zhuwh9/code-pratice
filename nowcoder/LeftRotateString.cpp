class Solution {
public:
    string LeftRotateString(string str, int n) {
        queue<char> q;
        for (int i = 0; i < str.size(); i++) {
            q.push(str[i]);
        }
        for (int i = 0; i < n; i++) {
            char t = q.front();
            q.pop();
            q.push(t);
        }
        string res = "";
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};
