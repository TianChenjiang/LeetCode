class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<int> dp;
        sort(envelopes.begin(), envelopes.end(), cmp);
        for (int i = 0; i < envelopes.size(); i++) {
            int left = 0, right = dp.size(), t = envelopes[i][1];
            while (left < right) {
                int mid = (left + right) >> 1;
                if (dp[mid] < t) left = mid + 1;
                else right = mid;
            }
            if (right >= dp.size()) dp.push_back(t);
            else dp[right] = t;
        }
        return dp.size();
    }

    static bool cmp(vector<int> a, vector<int> b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
};