class Solution {
public:
    string frequencySort(string s) {
        map<char,int> m;
        for (char ss : s) {
            m[ss]++;
        }
        vector<pair<char,int>> vec;
        for (auto & [c, freq] : m) {
            vec.push_back(make_pair(c, freq));
        }

        sort(vec.begin(), vec.end(), [] (pair<char,int> & p1, pair<char,int> & p2) -> bool {
            return p1.second > p2.second;
        });

        string res;
        for (auto [c, freq] : vec) {
            while (freq--) res += c;
        }
        return res;
    }
};