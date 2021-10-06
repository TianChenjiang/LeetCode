class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int> q;
        unordered_set<int> st;
        for (int num : nums) {
            if (!st.count(num)) {
                q.push(num);
                st.insert(num);
            }
        }
        if (q.size() < 3) return q.top();
        for (int i = 0; i < 2; i++) q.pop();
        return q.top();
    }
};