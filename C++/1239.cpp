class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        vector<string> dp;
        for (string str : arr) {
            if (hasRepeatedChar(str)) continue;
            for (int i = 0; i < dp.size(); i++) {
                string tmp = dp[i] + str;
                if (!hasRepeatedChar(tmp)) {
                    dp.push_back(tmp);
                }
            }
            dp.push_back(str);
        }
        int res = 0;
        for (string str : dp) {
            res = max((int)str.size(), res);
        }
        return res;
    }

    bool hasRepeatedChar(string str) {
        set<char> st;
        for (char chr : str) {
            st.insert(chr);
        }
        if (st.size() == str.size()) return false;
        return true;
    }
};