class Solution {
public:
    unordered_map<char, int> m;
    vector<string> findWords(vector<string>& words) {
        vector<string> keyboard = {"qwertyuiop", "asdfghjkl", "zxcvbnm"}, res;
        for (int i = 0; i < keyboard.size(); i++) {
            string str = keyboard[i];
            for (char c : str) m[c] = i;
        } 
        for (string word : words) {
            if (inOneLine(word)) res.push_back(word);
        }
        return res;
    }
    bool inOneLine(string word) {
        int line = m[tolower(word[0])];
        for (int i = 1; i < word.size(); i++) {
            if (line != m[tolower(word[i])]) return false;
        }
        return true;
    }
};