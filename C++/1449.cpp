class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        string res;
        vector<int> dp(target+1, INT_MIN);
        dp[0] = 0;
        for (int i = 1; i <= 9; i++) {
            int curCost = cost[i-1];
            for (int j = curCost; j <= target; j++) {
                dp[j] = max(dp[j], dp[j - curCost] + 1);
            }
        }
        
        if (dp[target] < 0) return "0";
        for (int i = 9, j = target; i >= 1; i--) {
            int curCost = cost[i-1];
            while (j >= curCost && dp[j] == dp[j - curCost] + 1) {
                res += to_string(i);
                j-=curCost;
            }
        }
        return res;
    }
};