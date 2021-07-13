class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res, h;
        multiset<int> s;
        for (auto b :  buildings) {
            h.push_back({b[0], -b[2]});
            h.push_back({b[1], b[2]});
        }
        sort(h.begin(), h.end());
        int pre = 0, cur = 0;
        s.insert(0);
        for (auto a : h) {
            if (a[1] < 0) s.insert(-a[1]);
            else s.erase(s.find(a[1]));
            cur = *s.rbegin();
            if (cur != pre) {
                res.push_back({a[0], cur});
                pre = cur;
            }
        }
        return res;
    }
};