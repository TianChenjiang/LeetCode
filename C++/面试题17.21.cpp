class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0, n = height.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && height[st.top()] < height[i]) { //不满足递减栈
                int t = st.top(); st.pop();
                if (st.empty()) break;
                int left = st.top();
                int curHeight = min(height[left], height[i]) - height[t];
                int curWidth = i - left - 1;
                res += curHeight * curWidth;
            }
            st.push(i);
        }
        return res;
    }
};