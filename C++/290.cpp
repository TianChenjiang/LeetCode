class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, int> m;
        stringstream st(s);
        string word;
        vector<char> p; unordered_set<char> set;
        vector<string> words; 
        int cnt = 0;
        
        while (st >> word) {
            words.push_back(word);
            if (m.find(word) == m.end()) {
                m[word] = cnt++;
            }
        }

        cnt = 0;
        for (char c : pattern) {
            if (set.insert(c).second) {
                p.push_back(c);
            }
        }

        string sPattern = "";
        for (string word : words) {
            int index = m[word];
            cout << index;
            if (index >= p.size()) return false;
            sPattern += p[index];
        }

        return sPattern == pattern;
    }
};