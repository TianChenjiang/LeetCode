class Solution {
    using ll = long long;
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        int s1 = numerator >= 0 ? 1 : -1;
        int s2 = denominator >= 0 ? 1 : -1;
        string res = "";
        if (s1 * s2 < 0) res += "-";
        ll num, den, quo, rem;
        num = ll(abs(numerator));
        den = ll(abs(denominator));
        quo = num / den;
        rem = num % den;
        unordered_map<ll, int> m;
        res += to_string(quo);
        if (rem == 0) return res;
        res += ".";
        string s = "";
        int pos = 0;
        while (rem != 0) {
            if (m.find(rem) != m.end()) {
                s.insert(m[rem], "(");
                s += ")";
                return res + s;
            }
            m[rem] = pos;
            s += to_string((rem * 10) / den);
            rem = (rem * 10) % den;
            pos++;
        }
        return res + s;
    }
};



