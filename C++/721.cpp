class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> res;
        unordered_map<string, string> root; 
        unordered_map<string, string> owner;
        unordered_map<string, set<string>> m;
        for (int i = 0; i < accounts.size(); i++) {
            vector<string> account = accounts[i];
            for (int j = 1; j < account.size(); j++) {
                root[account[j]] = account[j];
                owner[account[j]] = account[0];
            }
        }

        //链接同一个账号里的邮箱
        for (auto account : accounts) {
            string p = find(account[1], root);
            for (int i = 2; i < account.size(); i++) {
                root[find(account[i], root)] = p;
            }
        }

        for (auto account : accounts) {
            for (int i = 1; i < account.size(); i++) {
                m[find(account[i], root)].insert(account[i]);
            }
        }

        for (auto a : m) {
            vector<string> v(a.second.begin(), a.second.end());
            v.insert(v.begin(), owner[a.first]);
            res.push_back(v);
        }

        return res;
    }

    string find(string x, unordered_map<string, string>& root) {
        return x == root[x] ? x : find(root[x], root);
    }
};