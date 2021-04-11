class Solution {
public:
    int nthUglyNumber(int n) {
        int cnt = 1;
        int m2 = 0, m3 = 0, m5 = 0;
        vector<int> res(1, 1);
        while (res.size() < n) {
            int minNum = min(res[m2] * 2, min(res[m3] * 3, res[m5] * 5));
            if (minNum == res[m2] * 2) m2++;
            if (minNum == res[m3] * 3) m3++;
            if (minNum == res[m5] * 5) m5++;
            res.push_back(minNum);
        }
        return res.back();
    }
};