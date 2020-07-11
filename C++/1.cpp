class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]] = i;
        }

        vector<int> vec;
        for (int i = 0; i < nums.size(); i++) {
            int other = target - nums[i];
            map<int,int>::iterator iter = m.find(other);
            if (iter != m.end() && iter->second != i) {
                vec.push_back(i);
                vec.push_back(iter->second);
                return vec;
            }
        }
        vec.push_back(-1); vec.push_back(-1);
        return vec;
    }
};