class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int uglyNum = 1;
        priority_queue<long, vector<long>, greater<long>> q;
        unordered_set<long> st({1});
        q.push(1);
        for (int i = 0; i < n; i++) {
            int cur = q.top(); q.pop();
            uglyNum = (int)cur;
            for (int prime : primes) {
                long tmp = (long)prime * cur;
                if (!st.count(tmp)) {
                    st.insert(tmp);
                    q.push(tmp);
                }
            }
        }
        return uglyNum;
    }
};