class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> m;
        int visited[256] = {0};
        string res = "0";
        for (char c : s) m[c]++;
        for (char c : s) {
            m[c]--;
            if (visited[c]) continue;
            while (res.back() > c && m[res.back()]) { // 还得保证栈顶元素后面还有
                visited[res.back()]--;
                res.pop_back();
            }
            visited[c]++;
            res += c;
        }
        return res.substr(1);
    }
};