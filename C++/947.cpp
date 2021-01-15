class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int cnt = 0, n = stones.size();
        vector<int> root(n);
        for (int i = 0; i < n; i++) root[i] = i;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    root[getParent(root, i)] = getParent(root, j);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (root[i] == i) cnt++;
        }
        return n - cnt;
    }

    //递归找属于哪一类
    int getParent(vector<int>& root, int x) {
        return x == root[x] ? x : getParent(root, root[x]);
    }
};