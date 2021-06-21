class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 60; j++) {
                if (getBinOneNum(i) + getBinOneNum(j) == turnedOn) {
                    string hour = to_string(i) + ":";
                    string min = to_string(j);
                    if (j < 10) min = "0" + min; 
                    res.push_back(hour + min);
                }
            }
        }
        return res;
    }

    int getBinOneNum(int num) {
        int cnt = 0;
        while (num > 0) {
            if (num & 1) cnt++;
            num >>= 1;
        }
        return cnt;
    }
};