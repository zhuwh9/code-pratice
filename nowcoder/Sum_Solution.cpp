class Solution {
public:
    void recursive_add(int &sum, int curNum, int targetNum) {
        if (curNum <= targetNum) {
            sum += curNum;
            recursive_add(sum, curNum + 1, targetNum);
        }
    }
    int Sum_Solution(int n) {
        int sum = 0;
        recursive_add(sum, 1, n);
        return sum;
    }
};
