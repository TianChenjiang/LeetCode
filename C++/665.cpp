class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool isChanged = false;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] > nums[i] && !isChanged) {
                isChanged = true;
                if (i >= 2) {
                    if (nums[i-2] <= nums[i]) nums[i-1] = nums[i]; 
                    else nums[i] = nums[i-1];
                }
            } else if (nums[i-1] > nums[i] && isChanged){
                return false;
            } 
        }
        return true;
    }
};