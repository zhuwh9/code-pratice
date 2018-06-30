class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if (n == 0 || m == 0)
            return -1;
        queue<int> q;
        for (int i = 0; i < n; i++) {
            q.push(i);
        }
        int i = 0;
        while (q.size() > 1) {
            int front = q.front();
            q.pop();
            if (i != m - 1) {
                q.push(front);
                i++;
            }
            else
                i = 0;
        }
        return q.front();
    }
};
