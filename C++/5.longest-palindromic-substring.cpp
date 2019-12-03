#define MS 1000

class Solution {
public:
    string longestPalindrome(string s) {
        int a = 0;
        int b = 0; // j -> i a -> b
        //设计状态 dp[i][j] 表示i到j是否为回文串
        // 状态转移方程 dp[i][j] <- dp[i-1][j-1] & s[i] == s[j]
        int len = s.size();
        bool dp[MS][MS] = {false};
        for (int i = 0; i < len; i++) {
            dp[i][i] = true;
            for (int j = 0 ; j < i; j++) {
                dp[j][i] = (dp[j+1][i-1] || i - j < 2) && (s[i] == s[j]);
                if ((i - j > b - a) && dp[j][i] ) {a = j;b = i;}
            }
        }
      cout << a << " " << b;
      return s.substr(a, b-a+1);
    }
};