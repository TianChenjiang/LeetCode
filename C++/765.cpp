class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int N = row.size(), n = N / 2, res = 0;
        for (int i = 1; i < N; i+=2) {
            cout << row[i] << " " << row[i-1] << endl;
            if (!isNeighbor(row[i], row[i-1])) {
                for (int j = i + 1;  j < N; j++) {
                    if (isNeighbor(row[j], row[i-1])) {
                        swap(row[j], row[i]);
                        res++;
                        break;
                    }
                }
            }
            // for (int i = 0; i < N; i++) cout << row[i] << " ";
            // cout << endl;
        }
        return res;
    }
    bool isNeighbor(int a, int b) {
        if (a % 2 == 0) return b == a + 1;
        else return a == b + 1;
        // 上面两行等价于 return a == b ^ 1
    }
};