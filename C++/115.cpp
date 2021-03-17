class Solution {
public:
    int numDistinct(string s, string t) {
        const int N = 1002;
        long dp[N][N], sn = s.size(), tn = t.size();
        // dp[i][j]表示s.substr[0:i]和t[0:j]的匹配
        //t是空串
        for (int i = 0; i <= sn; i++) dp[i][0] = 1;
        for (int i = 1; i <= tn; i++) dp[0][i] = 0; //注意dp[0][0]是1
        for (int i = 1; i <= sn; i++) {
            for (int j = 1; j <= tn; j++) {
                dp[i][j] = dp[i-1][j] + ((s[i-1] == t[j-1])? dp[i-1][j-1] : 0);
            }
        }
        // for (int i = 0; i <= sn; i++) {
        //     for (int j = 0; j <= tn; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return dp[sn][tn];
    }
};