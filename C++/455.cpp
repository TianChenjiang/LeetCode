class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int res = 0, n = g.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int cnt = 0;
        for (int i = 0; i < n && cnt < s.size(); ) {
            if (s[cnt++] >= g[i]) {
                res++; i++; //注意点是满足了当前小朋友，才会满足下一个小朋友；所以可能遍历饼干更好
            }
        }
        return res;
    }
};