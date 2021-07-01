class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        queue<int> q({0});
        unordered_map<int, vector<int>> m;
        int step = 0, target = n-1, res = 0;

        for (auto r : relation) {
            m[r[0]].push_back(r[1]);
        }

        while (!q.empty() && step <= k) {
            step++;
            int nn = q.size();
            for (int i = 0; i < nn; i++) {
                int cur = q.front(); q.pop();
                for (int j = 0; j < m[cur].size(); j++) {
                    int t = m[cur][j];
                    cout << t << " ";
                    if (step == k && t == n-1) res++;
                    q.push(t);
                }
                cout << endl;
            }
        }
        return res;
    }
};