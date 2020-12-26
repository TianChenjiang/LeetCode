class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int res = 0, n = matrix.size();
        vector<int> height;
        for (int i = 0; i < n; i++) {
            height.resize(matrix[i].size());
            for (int j = 0; j < matrix[0].size(); j++) {
                height[j] = matrix[i][j] == '0' ? 0 : (height[j] + 1);
            }
            res = max(res, largestRectangleArea(height));
        }
        return res;
    }

    int largestRectangleArea(vector<int> height) {
        int res = 0;
        stack<int> s;
        height.push_back(0);
        for (int i = 0; i < height.size(); i++) {
            if (s.empty() || height[s.top()] <= height[i]) s.push(i);
            else {
                int tmp = s.top(); s.pop();
                res = max(res, height[tmp] * (s.empty() ? i : (i - s.top() - 1)));
                i--;
            }
        }
        return res;
    }
};