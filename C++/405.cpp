class Solution {
public:
    string toHex(int _num) {
        long num = _num;
        if (num == 0) return "0";
        if (num < 0) num = (long)(pow(2, 32) + num);
        string res = "";
        while (num > 0) {
            long reminder = num % 16;
            if (reminder >= 10) res += (reminder - 10 + 'a');
            else res += (reminder + '0');
            num /= 16;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};