#include<algorithm>
class Solution {
public:
    static bool cmp(pair<int, string> p1, pair<int, string> p2) {
        return p2.first < p1.first;
    }

    string intToRoman(int num) {
        string res = "";
        vector<pair<int, string>> m= {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };

        for (auto [number , roman] : m) {
            while (num >= number) {
                res += roman;
                num -= number;
            }
        }
        return res;
    }
};