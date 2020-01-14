/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
         stack<int> st;
        st.push(-1);
        int res = 0;
        int cur = 0;
        for (int i = 0; i < s.size(); i++) {
            char chr = s[i];
            if (chr == '(') st.push(i);
            else {
                st.pop();
                if (st.empty()) {
                    st.push(i);//新的开始
                } else {
                    res = max(res, i-st.top());
                }   
            }
        }
        return res;
    }
};
// @lc code=end

