class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> res;
        int n = groupSizes.size();
        unordered_map<int, vector<int>> m; //id - 序号索引

        for (int i = 0; i < n; i++) {
            int groupSize = groupSizes[i];
            m[groupSize].push_back(i);
        }

        for (auto [groupSize, ids] : m) { //[0,6,2,4,3,1] 
            vector<int> dummy;
            for (int id : ids) {
                dummy.push_back(id);
                if (dummy.size() == groupSize) {
                    res.push_back(dummy);
                    dummy.clear();
                }
            }
        }

        return res;
    }
};