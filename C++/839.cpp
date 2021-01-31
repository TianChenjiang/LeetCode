class Solution {
public:
    struct UnionSet {
        static const int N = 1001;
        int f[N], cnt = 0;

        void init(int n) {
            for (int i = 0; i < n; i++) {
                f[i] = i;
            }
        }

        int find(int x) {
            return x == f[x] ? x : f[x] = find(f[x]);
        }

        int merge(int x, int y) {
            int setX = find(x);
            int setY = find(y);
            if (setX == setY) {
                return false;
            }
            f[setX] = setY;
            cnt++;
            return true;
        }
    }us;

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size(), res = 0;
        us.init(n);
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (isSimilar(strs[i], strs[j])) {
                    us.merge(i, j);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (us.f[i] == i) res++;
        }
        return res;
    }

    bool isSimilar(string str1, string str2) {
        int num = 0;
        for (int i = 0; i < str1.size(); i++) {
            if (str1[i] != str2[i]) {
                num++;
            }
            if (num > 2) return false;
        }
        return true;
        // char c1 = ' ', c2 = ' ';
        // for (int i = 0; i < str1.size(); i++) {
        //     if (str1[i] != str2[i] && c1 == ' ') {
        //         c1 = str1[i], c2 = str2[i];
        //     } else if (str1[i] != str2[i] && c1 != ' ') {
        //         if (c1 == str2[i] && c2 == str1[i]) {
        //             cout << str1 << " " << str2 << endl;
        //             return true;
        //         } else return false;
        //     }
        // }
        // return false;
    }
};