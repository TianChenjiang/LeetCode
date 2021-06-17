class Solution {
public:
    bool isNumber(string s) {
        //用e将该数字分为两部分，前面是整/小数，后面是整数
        int eIndex = -1;
        for (int i = 0; i < s.size(); i++) {
            int chr = s[i];
            if (chr == 'e' || chr == 'E') {
                if (eIndex != -1) return false;
                eIndex = i;
                if (eIndex == s.size()) return false;
            }
        }
        if (eIndex == -1) return check(s, 0, s.size() - 1, 0);
        return check(s, 0, eIndex - 1,0) && check(s, eIndex + 1, s.size() - 1, 1);
    }

    bool check(string s, int start, int end, int mustInteger) {
        bool hasSignal = false, hasDecimalPoint = false, hasNum = false;
        
        for (int i = start; i <= end; i++) {
            char chr = s[i];
            if ((chr < '0' || chr > '9') && chr != 'E' && chr != 'e' 
                && chr != '.' && chr != '-' && chr != '+') return false;
            if (chr >= '0' && chr <= '9') hasNum = true;
            if (chr == '+' || chr == '-') {
                if (hasSignal) return false;
                hasSignal = true;
            } 
            if (chr == '.') {
                if (hasDecimalPoint) return false;
                hasDecimalPoint = true;
            }
            if (i == start && !hasSignal) hasSignal = true;
        }
        if (hasDecimalPoint && mustInteger || !hasNum) return false;
        return true;
    }
};