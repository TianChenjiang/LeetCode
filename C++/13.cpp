class Solution {
public:
    int romanToInt(string s) {
        s += "Z";
        int res = 0;
        unordered_map<string, int> m= {
            {"M", 1000},
            {"CM", 900},
            {"D", 500},
            {"CD", 400},
            {"C", 100},
            {"XC", 90},
            {"L", 50},
            {"XL",40},
            {"X", 10},
            {"IX", 9},
            {"V", 5},
            {"IV", 4},
            {"I", 1},
            {"Z", 0}
        };
        if (m[s] != 0) return m[s];
        for (int i = 1; i < s.size(); i++) {
            string low = string(1, s[i]), high = string(1, s[i-1]);
            if (m[low] > m[high]) {
                res += m[high + low];
                i++;
            }
            else {
                res += m[high];
            }
        }
        return res;
    }
};