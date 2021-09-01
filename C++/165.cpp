class Solution {
public:
    int compareVersion(string version1, string version2) {
        auto v1 = formatting(version1);
        auto v2 = formatting(version2);
        int s1 = v1.size(), s2 = v2.size();
        if (s1 < s2) {
            while (s1 < s2) {
                v1.push_back(0);
                s1++;
            }
        } else {
            while (s1 > s2) {
                v2.push_back(0);
                s2++;
            }
        }
        if (v1 > v2) return 1;
        if (v1 < v2) return -1;
        return 0;
    }
    
    vector<long long> formatting(string version) {
        version += ".";
        vector<long long> res;
        int n = version.size(), last = -1;
        for (int i = 0; i < n; i++) {
            if (version[i] == '.') {
                long long tmp = 0, cnt = 0;
                for (int j = i-1; j > last; j--) {
                    tmp += (version[j] - '0') * pow(10, cnt);
                    cnt++;
                }
                last = i;
                res.push_back(tmp);
            }
        }
        return res;
    }
};