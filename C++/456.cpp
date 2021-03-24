class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int third = INT_MIN;
        stack<int> st; //递减栈，栈中的元素均大于third
        for (int i = nums.size()-1; i >= 0; i--) {
            if (nums[i] < third) return true;
            while (!st.empty() && st.top() < nums[i]) {
                third = st.top(); st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};