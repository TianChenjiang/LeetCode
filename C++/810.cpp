class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int xorSum = 0, n = nums.size();
        if (n % 2 == 0) return true;
        for (int num : nums) xorSum ^= num;
        //模拟回合
        return xorSum == 0;
    }
};