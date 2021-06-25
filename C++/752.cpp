class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadendsSet(deadends.begin(), deadends.end());
        int cnt = INT_MAX;
        string start = "0000";
        unordered_set<string> visited({start});
        if (deadendsSet.count(start)) return -1;
        if (target == start) return 0;
        int res = 0;
        
        queue<string> q({start});
        while (!q.empty()) {
            res++;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                string cur = q.front(); q.pop();
                for (int j = 0; j < 4; j++) {
                    for (int k = -1; k <= 1; k+=2) {
                        string newLock = cur;
                        newLock[j] = (newLock[j] - '0' + 10 + k) % 10 + '0';
                        if (newLock == target) return res;
                        if (!deadendsSet.count(newLock) && !visited.count(newLock)) q.push(newLock);
                        visited.insert(newLock);
                    } 
                }
            }
        }
        return -1;
    }
};