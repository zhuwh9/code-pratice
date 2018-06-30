class Solution {
public:
    int Add(int a, int b)
    {
        if (b == 0)
            return a;
        int sum = a ^ b;
        int carry = (a & b) << 1;
        return Add(sum, carry);
    }
};
