class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string str = to_string(N);
        int n = str.size(), j = n;
        for (int i = n-1; i > 0; i--) {
            if (str[i] < str[i-1]) {
                str[i-1]--;
                j = i;  //记录最高的变化的位置，后面的都可以变为9
            }
        }
        for (; j < str.size(); j++) {
            str[j] = '9';
        }
        return stoi(str);
    }
};