class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size(), target = n / 3 + 1;
        vector<int> res;
        unordered_map<int, int> m;
        for (int num : nums) {
            if (m[num] == -1) continue;
            m[num]++;
            if (m[num] >= target){
                res.push_back(num);
                m[num] = -1;
            }
        }
        return res;
    }
};