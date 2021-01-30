class Solution {
public:
    struct UnionSet {
        static const int N = 2501;
        int f[N];
        
        void init(int n) {
            for (int i = 0; i < n; i++) f[i] = i;
        }

        int find(int x) {
            return x == f[x] ? x : f[x] = find(f[x]);
        }

        bool merge(int x, int y) {
            int setX = find(x);
            int setY = find(y);
            if (setX == setY) return false;
            f[setX] = setY;
            return true;
        }

        bool isConnected(int x, int y) {
            return find(x) == find(y);
        }
    }us;

    int swimInWater(vector<vector<int>>& grid) {
        int t = 0, n = grid.size();
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        us.init(n*n);

        int index[us.N];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                index[grid[i][j]] = i * n + j; //这一步很巧妙 下标：方格的高度，值：对应在方格中的坐标
            }
        }

        for (int i = 0; i < n * n; i++) { //模拟时间
            int x = index[i] / n;
            int y = index[i] % n;
            for (auto dir : dirs) {
                int newX = x + dir[0];
                int newY = y + dir[1];
                if (inArea(newX, newY, n) && grid[newX][newY] <= i) {
                    us.merge(index[i], newX * n + newY);
                }
            }
            if (us.isConnected(0, n*n-1)) {
                return i;
            }
        }
        return -1;
    }

    bool inArea(int x, int y, int n) {
        return x >= 0 && y >= 0 && x < n && y < n;
    }
};