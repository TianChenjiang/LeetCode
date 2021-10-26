class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> res;
        for (int i = 0; i < n; i++) {
            int target = nums1[i], j = 0;
            while (j < m && target != nums2[j]) j++;
            while (j < m && target >= nums2[j]) j++;
            if (j < m) res.push_back(nums2[j]);
            else res.push_back(-1);
        }
        return res;
    }
};