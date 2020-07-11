class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) return s;
        bool dp[1005][1005];

        dp[0][0] = true;
        for (int i = 1; i < s.size(); i++) {
            dp[i][i-1] = true;
            dp[i][i] = true;
        }
        
        string ans = string(1,s[0]);
        for (int l = 2; l <= s.size(); l++) {
            for (int i = 0; i <= s.size()-l; i++) {
                int j = l + i -1; //l = j-i+1
                dp[i][j] = dp[i+1][j-1] && s[i] == s[j];
                //  if (i == 0 && j == 3) cout << dp[1][2] << endl;
                if (dp[i][j]) {
                    if (l > ans.size()) {
                        ans = s.substr(i, l);
                    }
                }
            }
        }

        // for (int i = 0; i < s.size(); i++) {
        //     for (int j = 0; j < s.size(); j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return ans;
    }
};