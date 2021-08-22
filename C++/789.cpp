class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        vector<int> start({0,0});
        vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        int dis = getManhattanDis(start, target);
        for (auto ghost : ghosts) {
            if (getManhattanDis(ghost, target) <= dis) return false;
        }
        return true;
    }
    int getManhattanDis(vector<int> origin, vector<int> target) {
        return abs(origin[0] - target[0]) + abs(origin[1] - target[1]);
    }
};