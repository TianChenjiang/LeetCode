class Solution {
public:
    bool checkValidString(string s) {
        int optionNum = 0;
        stack<int> lSt, aSt;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                lSt.push(i);
            } else if (s[i] == ')') {
                if (!lSt.empty()) lSt.pop();
                else if (!aSt.empty()) aSt.pop();
                else return false;
            } else aSt.push(i);
        }
        // 现在所有)匹配完毕，把剩余的(和*匹配
        while (!lSt.empty() && !aSt.empty()) {
            int l = lSt.top(), a = aSt.top();
            if (l > a) return false;
            lSt.pop(); aSt.pop();
        }
        return lSt.empty();
    }
};