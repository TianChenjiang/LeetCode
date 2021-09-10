class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long chalkSum = 0;
        for (int i = 0; i < chalk.size(); i++) chalkSum += chalk[i];
        k %= chalkSum;
        for (int i = 0; i < chalk.size(); i++) {
            if (k < chalk[i]) return i;
            k -= chalk[i];
        }
        return 0;
    }
};