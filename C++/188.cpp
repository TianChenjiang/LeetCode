class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) return 0;
        int n = prices.size();
        k = min(k, n/2);
        vector<int> sell(k+1), buy(k+1, INT_MIN);

        for (int price : prices) {
            for (int i = 1; i <= k; i++) {
                buy[i] = max(buy[i], sell[i-1] - price);
                sell[i] = max(sell[i], buy[i] + price);
            }
        }
        return sell[k];
    }
};