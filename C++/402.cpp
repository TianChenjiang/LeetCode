class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";
        int n = num.size(), keep = n - k;
        for (char c : num) {
            while (k && res.size() && res.back() > c) { //相当于一个递增单调栈，去除高位数字收益最大
                res.pop_back();
                k--;
            }
            res.push_back(c);
        }
        res.resize(keep); //对于测试用例 "9" 1
        while (res[0] == '0' && !res.empty()) res.erase(res.begin()); //去除前导0
        return res.empty() ? "0" : res;
    }
};