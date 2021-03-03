class Solution {
public:
    vector<int> countBits(int num) {
        // vector<int> res;
        // for (int i = 0; i <= num; i++) {
        //     int n = i, cnt = 0;
        //     while (n > 0) {
        //         cnt += n & 1;
        //         n >>= 1;
        //     }
        //     res.push_back(cnt);
        // }
        // return res;
        vector<int> res(num+1);
        for (int i = 0; i <= num; i++) {
            if (i % 2 == 0) {
                res[i] = res[i/2];
            } else {
                res[i] = res[i-1] + 1;
            }
        }
        return res;
    }
};