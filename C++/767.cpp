class Solution {
public:
    string reorganizeString(string S) {
        int freq[26] = {0};
        int len = S.size();
        for (int i = 0; i < len; i++) {
            freq[S[i] - 'a']++;
        }

        string res = "";
        priority_queue<pair<int, char>> q;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > (len + 1) / 2) return "";
            if (freq[i] != 0) {
                q.push({freq[i], 'a' + i});
            }
        }

        while (q.size() >= 2) {
            auto p1 = q.top(); q.pop();
            auto p2 = q.top(); q.pop();
            res += p1.second;
            res += p2.second;
            if (--p1.first > 0) q.push(p1);
            if (--p2.first > 0) q.push(p2);
        }
        if (!q.empty()) {
            res += q.top().second;
        }
        return res;
    }
};