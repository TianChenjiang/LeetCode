class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        vector<vector<string>> res;
        unordered_map<string, unordered_map<string, int>> m; //桌号 - 菜品
        set<string> st;
        set<int> ids;
        for (auto order : orders) {
            string tableNum = order[1];
            st.insert(order[2]);
            m[tableNum][order[2]]++;
            ids.insert(stoi(tableNum));
        }

        vector<string> firstLine({"Table"});
        for (auto it = st.begin(); it != st.end(); it++) firstLine.push_back(*it);
        res.push_back(firstLine);
        for (int id : ids) {
            string idStr = to_string(id);
            vector<string> cur({idStr});
            auto meanu = m[idStr];
            for (int i = 1; i < firstLine.size(); i++) {
                cur.push_back(to_string(meanu[firstLine[i]]));
            }
            res.push_back(cur);
        }
        return res;
    }
};