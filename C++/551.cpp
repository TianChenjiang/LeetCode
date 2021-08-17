class Solution {
public:
    bool checkRecord(string s) {
        int aNum = 0, Lcontinue = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') Lcontinue++;
            else Lcontinue = 0;
            if (Lcontinue >= 3) return false;
            if (s[i] == 'A') aNum++;
            if (aNum >= 2) return false;
        }
        return true;
    }
};