class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> res, m(n, vector<int>());
        for (int i = 0; i < n; i++) {
            for (int j : graph[i]) m[i].push_back(j);
        }
        vector<int> path(1,0);
        dfs(graph, res, 0, n - 1, path);
        return res;
    }

    void dfs(vector<vector<int>>& graph, vector<vector<int>>& res, int cur, int target, vector<int>& path) {
        if (cur == target) {
            res.push_back(path);
        }
        for (int i = 0; i < graph[cur].size(); i++) {
            path.push_back(graph[cur][i]);
            dfs(graph, res, graph[cur][i], target, path);
            path.pop_back();
        }
    }
};