class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> previousLine;
        for (int i = 0; i < numRows; i++) {
            int num = i + 1;
            vector<int> line; line.resize(num);
            if (i == 0) {
                res.push_back({1});
                continue;
            }
            line[0] = 1, line[num-1] = 1;
            for (int j = 1; j < num-1; j++) {
                line[j] = previousLine[j-1] + previousLine[j];
            }
            previousLine = line;
            res.push_back(line);
        }
        return res;
    }
};