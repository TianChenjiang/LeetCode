class Solution {
public:
    int xorOperation(int n, int start) {
        int res = 0;
        for (int i = start; i < start + n * 2; i+=2) {
            res ^= i;
        }
        return res;
    }
};