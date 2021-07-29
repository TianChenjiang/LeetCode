class Solution {
public:
    int getRow(int label) {
        int num = 0;
        for (int i = 0; ; i++) {
            num += pow(2, i);
            if (label <= num) return i + 1;
        }
        return -1;
    }

    vector<int> pathInZigZagTree(int label) {
        int row = getRow(label);
        vector<int> res(row);
        while (row >= 1) {
            res[--row] = label;
            label = (pow(2, row)  + pow(2, row + 1) - 1 - label) / 2;
        }
        return res;
    }

};