class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size(), res = 1;
        vector<int> up(n, 1), down(n, 1);
        for (int i = 1; i < n; i++) {
            if (arr[i-1] > arr[i]) {
                up[i] = down[i-1] + 1;
            } else if (arr[i-1] < arr[i]){
                down[i] = up[i-1] + 1;
            }
            res = max(res, max(up[i], down[i]));
        }
        return res;
    }
};