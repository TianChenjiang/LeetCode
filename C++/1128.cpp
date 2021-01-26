class Solution {
public:
    string adjustIncreasingString(vector<int>& domino) {
        if (domino[0] < domino[1]) return to_string(domino[0]) + " " + to_string(domino[1]);
        else {
            return to_string(domino[1]) + " " + to_string(domino[0]);
        }
    }

    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int res = 0;
        unordered_map<string, int> m;
        for (auto domino : dominoes) {
            string tmp = adjustIncreasingString(domino);
            m[tmp]++;
        }
        for (auto &[str, n] : m) {
            if (n > 1) res += n * (n - 1) / 2;
        }
        return res;
    }
};