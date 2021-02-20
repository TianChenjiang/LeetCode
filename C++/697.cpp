class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        int degree = 0, n = nums.size(), res = INT_MAX;
        unordered_map<int, int> m;
        unordered_map<int, pair<int, int>> pos;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            degree = max(degree, ++m[num]);
            if (m[num] == 1) pos[num] = {i, i};
            else pos[num].second = i;
        }

        for (auto p : m) {
            int num = p.first;
            if (m[num] == degree) res = min(pos[num].second - pos[num].first + 1, res);
        }

        // int l = 0, r = 0, n = nums.size();
        // int num = -1, target = degree, res = INT_MAX;
        // while (r < n) {
        //     target = degree - 1;
        //     num = nums[r];
        //     l = r - 1;
        //     while (target != 0 && l >= 0) {
        //         if (nums[l] == num) target--;
        //         if (l > 0 && target != 0) l--; else break;
        //     }

        //     if (target == 0) {
        //         res = min(r - l + 1, res);
        //         cout << r << " " << l;
        //     }
        //     r++;
        // }
        return res;
    }
};