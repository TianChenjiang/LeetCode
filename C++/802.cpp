class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> res, color(n);
        // 0 - while 1 - gray 2 - black 
        for (int i = 0; i < n; i++) {
            if (helper(graph, i, color)) res.push_back(i);
        }
        return res;
    }

    bool helper(vector<vector<int>>& graph, int i, vector<int>& color) {
        if (color[i] == 2) return true;
        if (color[i] == 1) return false;
        color[i] = 1;
        for (int next : graph[i]) {
            if (!helper(graph, next, color)) return false;
        }
        color[i] = 2;
        return true;
    }

};