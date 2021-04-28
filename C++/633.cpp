class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int a = 0; a <= int(sqrt(c)); a++) {
            int b = c - a * a;
            int bb = int(sqrt(b));
            if (bb * bb == b) {
                return true;
            }
        }
        return false;
    }
};