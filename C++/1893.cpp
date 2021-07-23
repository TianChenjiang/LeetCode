class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> diff(52);
        for (auto range : ranges) {
            diff[range[0]]++;
            diff[range[1]+1]--;
        }
        int cur = 0;
        for (int i = 1; i <= 50; i++) {
            cur += diff[i];
            if (left <= i && i <= right && cur <= 0) return false;
        }
        return true;
    }
};