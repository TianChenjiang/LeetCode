class Solution {
public:
    const int N = 50000;
    int maxProfit(vector<int>& prices, int fee) {
        int hold[N], sell[N];  //第i天有股票，没股票的利润
        int n = prices.size();
        sell[0] = 0, hold[0] = -prices[0];
        for (int i = 1; i < n; i++) {
            hold[i] = max(hold[i-1], sell[i-1] - prices[i]);
            sell[i] = max(sell[i-1], hold[i-1] + prices[i] - fee);
            // cout << hold[i] << " " << sell[i] << endl;
        }
        return sell[n-1];
    }
};