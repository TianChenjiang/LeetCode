class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> res;
        int n = arr.size();
        vector<int> dp(n); dp[0] = arr[0];
        for (int i = 1; i < n; i++) {
            dp[i] = dp[i-1] ^ arr[i];
        }
        for (vector<int> query : queries) {
            int l = query[0], r = query[1];
            int tmp = 0;
            tmp = (l == 0) ? dp[r] : dp[r] ^ dp[l-1];
            res.push_back(tmp);
        }           
        return res;
    }
};