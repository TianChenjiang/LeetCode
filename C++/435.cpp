class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int res = 0, n = intervals.size();
        int last = 0;
        sort(intervals.begin(), intervals.end()); // 根据start进行升序
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] < intervals[last][1]) {
                res++;
                if (intervals[i][1] < intervals[last][1]) last = i; // 看删除哪一个
            } else last = i;
        }
        return res;
    }
};