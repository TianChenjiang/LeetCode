class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            res.push_back(i+1);
        }
        for (int i = 0; i < n; i++) {
            res[nums[i]-1] = -1;
        }

        // res.erase(remove(res.begin(),res.end(),-1),res.end());
        for (auto it = res.begin(); it != res.end();) {
            if ((*it) == -1) {
                it = res.erase(it);
                if (it == res.end()) break;
            } else it++;
        }
        return res;
    }
};