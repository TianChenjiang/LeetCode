class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (!n) return tasks.size();
        unordered_map<char,int> freq;
        priority_queue<int> q;

        for (char task : tasks) freq[task]++;
        int res = 0, cycle = n + 1;
        for (auto task : freq) {
            q.push(task.second);
        }

        while (!q.empty()) {
            int cnt = 0;
            vector<int> t;
            for (int i = 0; i < cycle; i++) {
                if (!q.empty()) {
                    t.push_back(q.top()); q.pop();
                    cnt++;
                }
            }
            for (int d : t) {
                if (--d > 0) q.push(d);
            }
            res += q.empty() ? cnt : cycle; //为空说明做到最后一步了
        }
        return res;
    }
};