class Solution {
public:
    string predictPartyVictory(string senate) { //ban掉别人的放到下一轮
        int n = senate.size();
        queue<int> q1, q2;
        for (int i = 0; i < senate.size(); i++) {
            (senate[i] == 'R') ? q1.push(i) : q2.push(i);
        }
        while (!q1.empty() && !q2.empty()) {
            int i = q1.front(); q1.pop();
            int j = q2.front(); q2.pop();
            (i < j) ? q1.push(i+n) : q2.push(i+n);
        }
        return (q1.empty()) ?  "Dire" :  "Radiant";
    }
};