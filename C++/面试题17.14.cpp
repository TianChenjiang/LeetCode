class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        vector<int> res;
        for (int num : arr) q.push(num);
        for (int i = 0; i < k; i++) {
            int t = q.top(); q.pop();
            res.push_back(t);
        }
        return res;
    }
};