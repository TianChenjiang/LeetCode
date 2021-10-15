class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for (int i = 2; i <= n; i++) {
            string tmp = "";
            for (int j = 0; j < res.size(); j++) {
                int cnt = 1;
                char cur = res[j];
                while (cur == res[++j] && j < res.size()) cnt++;
                tmp += to_string(cnt) + string(1, cur);
                j--;
            }
            res = tmp;
        }
        return res;
    }
};