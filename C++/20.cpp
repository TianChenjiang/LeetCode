/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
#include<iostream>
#include<map>
#include<stack>
#include<string>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        map<char, char> m = {{'{', '}'}, {'(',')'}, {'[',']'}};
        if (s.size() % 2 != 0) {return false;}
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if (st.empty()) {return false;}
                char c = s[i];
                char top = st.top();
                st.pop();
                if (m[top] != s[i]) {
                    return false;
                }
            }
        }
        if (!st.empty()) {
            return false;
        } else {
            return true;
        }
    }
};


int main() {
    Solution s;
    cout << s.isValid(")");
}
// @lc code=end

