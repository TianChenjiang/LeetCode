class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int res = 0, n = price.size();
        for (int i = 0; i < n; i++) {
            res += price[i] * needs[i];
        }
        for (auto coupon : special) {
            bool isVaild = true;
            for (int i = 0; i < n; i++) {
                if (needs[i] < coupon[i]) isVaild = false;
                needs[i] -= coupon[i];
            }
            if (isVaild) res = min(res, shoppingOffers(price, special, needs) + coupon.back());
            for (int i = 0; i < n; i++) {
                needs[i] += coupon[i];
            }
        }
        return res;
    }
};