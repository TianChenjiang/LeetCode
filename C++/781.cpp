class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int res = 0;
        unordered_map<int, int> m;
        for (int a : answers) m[a]++;
        for (auto mm : m) {
            res += (mm.first + mm.second) / (mm.first + 1) * (mm.first + 1);
        }
        return res;
    }
};