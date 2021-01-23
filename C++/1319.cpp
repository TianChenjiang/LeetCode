class Solution {
public:
    static const int N = 100001;
    struct UnionSet {
        int f[N];

        void init(int n) {
            for (int i = 0; i < n; i++) f[i] = i;
        }

        int find(int x) {
            return x == f[x] ? x : find(f[x]);
        }
        
        bool merge(int x, int y) {
            int setX = find(x);
            int setY = find(y);
            if (setX == setY) return false;
            f[setX] = setY;
            return true;
        }
    }us;

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (n-1 > connections.size()) return -1;
        int cnt = 1;
        us.init(n);
        for (auto connection : connections) {
            if (us.merge(connection[0], connection[1])) {
                cnt++;
            }
        }
        return n-cnt;
    }
};