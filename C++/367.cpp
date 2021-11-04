typedef long long ll;
class Solution {
public:
    bool isPerfectSquare(int num) {
        for (int i = 0; i <= num; i++) {
            ll tmp = (ll)i * i;
            if (tmp == num) return true;
            if (tmp > num) return false;
        }
        return false;
    }
};