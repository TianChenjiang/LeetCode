class Solution {
public:
    bool detectCapitalUse(string word) {
        bool hasLower = false, hasUpper = false;
        if (islower(word[0])) hasLower = true;
        for (int i = 1; i < word.size(); i++) {
            if (islower(word[i])) {
                hasLower = true;
            } else {
                hasUpper = true;
            }
            
        }
        return !(hasLower && hasUpper);
    }
};