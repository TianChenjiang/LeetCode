class Solution {
private:
    int n = 0, sum = 0;
    vector<int> preSum;
public:
    Solution(vector<int>& w) {
        n = w.size();
        sum = accumulate(w.begin(), w.end(), 0);
        preSum.resize(n+1);
        for (int i = 1; i <= n; i++) {
            preSum[i] = preSum[i-1] + w[i-1];
        }
        
    }
    
    int pickIndex() {
        int random = rand() % sum;
        int lo = 0, hi = n + 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (preSum[mid] > random) hi = mid;
            else lo = mid + 1;
        }
        return --lo;
        // return upper_bound(preSum.begin(), preSum.end(), random) - preSum.begin() - 1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */