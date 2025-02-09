class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res;
        for (int i = 0; i < 32; i++) {
            if (n & 1 == 1) res = (res << 1) + 1;
            else res = res << 1;
            n = n >> 1;
        }
        return res;
    }
};