class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int countOf5 = 0, coutOf10 = 0;
        for (int bill : bills) {
            if (bill == 5) {
                countOf5++;
            } else if (bill == 10) {
                if (countOf5 != 0) {
                    countOf5--;
                    coutOf10++;
                } else return false;
            } else {
                if (countOf5 > 0 && coutOf10 > 0) {
                    countOf5--;
                    coutOf10--;
                }
                else if (countOf5 >= 3) {
                    countOf5-=3;
                }
                else return false;
            }
        }
        return true;
    }
};