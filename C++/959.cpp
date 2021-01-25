class Solution {
public:
    static const int N = 31;
    struct UnionSet {
        int f[N * N * 4], cnt;

        void init(int n) {
            for (int i = 0; i < n; i++) f[i] = i;
            cnt = n;
        }

        int find(int x) {
            return x == f[x] ? x : f[x] = find(f[x]);
        }

        bool merge(int x, int y) {
            int setX = find(x);
            int setY = find(y);
            if (setX == setY) return false;
            else {
                f[setX] = setY;
                cnt--;
                return true;
            }
        }
    }us;

    int regionsBySlashes(vector<string>& grid) {
        int res = 0, n = grid.size();
        int size = 4 * n * n;
        us.init(size);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) { 
                int idx = 4 * (i * n + j); //表示第几个小格子
                // 单元格内合并
                if (grid[i][j] == '/') {
                    us.merge(idx, idx + 3);
                    us.merge(idx + 1, idx + 2);
                } else if (grid[i][j] == '\\') {
                    us.merge(idx, idx + 1);
                    us.merge(idx + 2, idx + 3);
                } else {
                    us.merge(idx, idx + 1);
                    us.merge(idx + 1, idx + 2);
                    us.merge(idx + 2, idx + 3);
                }
                //单元格间合并
                if (j + 1 < n) {
                    us.merge(idx + 1, 4 * (i * n + j + 1) + 3);
                }
                if (i + 1 < n) {
                    us.merge(idx + 2, 4 * ((i + 1) * n + j));
                }
            }
        }
        return us.cnt;
    }
};