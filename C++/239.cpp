class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k){
        vector<int> res;
        int n = nums.size();
        multiset<int> st;
        for (int i = 0; i < n; i++) {
            if (i >= k) st.erase(st.find(nums[i-k]));
            st.insert(nums[i]);
            if (i >= k-1) res.push_back(*st.rbegin());
        }
        return res;
    }
};