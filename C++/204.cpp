class Solution {
public:
    int countPrimes(int n) {
        int res = 0;

        for (int i = 0; i < n; i++) {
            if (isPrime(i)) {
                res++;
            }
        }
        return res;
    }
    bool isPrime(int num) {
        if (num <= 1) return false;
        if (num == 2) return true;
        for (int i = 2; i < sqrt(num) + 1; i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
};