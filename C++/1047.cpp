class Solution {
public:
    string removeDuplicates(string S) {
        string res;
        for (char chr : S) {
            if (!res.empty() && chr == res.back()) {
                res.pop_back();
            } else {
                res.push_back(chr);
            }
        }
        return res;
    }
};