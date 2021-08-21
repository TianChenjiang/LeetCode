class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(), cur = 0;
        for (int i = 0; i < n; i++) {
            int j = i+1, cnt = 0;
            while (j < n && chars[j] == chars[i]) j++;
            chars[cur++] = chars[i];
            if (j - i == 1) continue;
            for (char c : to_string(j - i)) chars[cur++] = c;
            i = j - 1;
        }
        return cur;
    }
};