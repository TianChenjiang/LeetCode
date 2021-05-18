class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size(), res = 0;
        vector<int> xorSum(n+1);
        xorSum[0] = 0;
        for (int i = 0; i < n; i++) {
            xorSum[i+1] = xorSum[i] ^ arr[i];
        }

        // s[j]^ s[i] = s[k+1] ^ s[j]
        for (int i = 0; i < n; i++) {
            for (int k = i + 1; k < n; k++) {
                if (xorSum[i] == xorSum[k+1]) {
                    // i+1 到 k的所有j都满足题意
                    res += k - i;
                }
            }
        }
        return res;
    }
};