class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        vector<int> res;
        int total = 0, odd = 0, n = encoded.size(), first = 0;
        for (int i = 1; i <= n+1; i++) {
            total ^= i;
        }
        for (int i = 1; i < n; i+=2) {
            odd ^= encoded[i];
        }

        // first ^ odd = total
        first = total ^ odd;
        res.push_back(first);
        cout << first;
        for (int i = 0; i < encoded.size(); i++) {
            //perm[i] ^ perm[i+1] = encoded[i]
            res.push_back(res[i] ^ encoded[i]);
        }
        return res;
    }
};