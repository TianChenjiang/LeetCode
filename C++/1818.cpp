class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(); int res = 0;
        int MOD = pow(10, 9) + 7;
        vector<int> vec(nums1);
        sort(vec.begin(), vec.end());
        int maxExange = 0; //比起某个位置的diff，在交换后能额外小多少
        for (int i = 0; i < n; i++) {
            int diff = abs(nums1[i] -  nums2[i]);
            res = (res + diff) % MOD;
            //找最接近nums2[i]的nums1
            int index = lower_bound(vec.begin(), vec.end(), nums2[i]) - vec.begin();
            //min (>= nums2[i])
            if (index < n) maxExange = max(maxExange, diff - (vec[index] - nums2[i])); 
            // nums2[i] > 所有nums1
            if (index > 0)  maxExange = max(maxExange, diff - (nums2[i] - vec[index-1]));
        }
        return (int)(res - maxExange + MOD) % MOD;
    }
};