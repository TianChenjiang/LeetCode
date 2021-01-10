class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        for (int i = 0; i < nums.size(); i++) {
            int start = i, end = i+1;
            while (end < nums.size() && nums[end] == nums[end-1]+1) end++;
            string tmp = to_string(nums[start]);
            tmp += (nums[start] == nums[end-1]) ? "" : ("->" + to_string(nums[end-1]));
            i = end-1;
            res.push_back(tmp);
        }
        return res;
    }
};