class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        int res = m * (1 << (n-1)); //第一列肯定要都搞为1
        for (int i = 1; i < n; i++) {
            int cnt = 0; //比较0和1的个数
            for (int j = 0; j < m; j++) { // 如果和最高位一开始相同，经过横竖翻转仍然会相同
                cnt += (A[j][i] == A[j][0]);
            }
            res += max(cnt, m - cnt) * (1 << (n - 1 - i)); //选每一列中0/1中数量多的那个
        }
        return res;
    }
};