class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        int res = 0;
        vector<vector<int>> vec(n, vector<int>(n, 1));
        for (int i = 0; i < n; i++) {
            int cnt = n;
            for (int j = 0; j < n - 1; j++) {
                vec[i][preferences[i][j]] = cnt--;
            }
        }

        vector<int> m(n);
        for (auto pair : pairs) {
            m[pair[0]] = pair[1];
            m[pair[1]] = pair[0];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == i || j == m[i]) continue;
                if (vec[i][j] > vec[i][m[i]] && vec[j][i] > vec[j][m[j]]) {
                    res++;
                    break;
                }
            }
        }
        
        return res;
    }
};