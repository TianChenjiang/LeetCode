class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = "";
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                start += to_string(board[i][j]);
            }
        }
        // 1 2 3
        // 4 0 5
        string target = "123450";
        queue<string> q({start});
        unordered_set<string> visited({start});
        int res = 0;

        // 手动枚举所有0可能去到的位置
        vector<vector<int>> dirs = {{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        if (start == target) return 0;

        while (!q.empty()) {
            res++;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                string cur = q.front(); q.pop();
                int zeroIndex = cur.find("0");
                for (int dest : dirs[zeroIndex]) {
                    string newBoard = cur;
                    swap(newBoard[zeroIndex], newBoard[dest]);
                    cout << newBoard << endl;
                    if (newBoard == target) return res;
                    if (!visited.count(newBoard)) q.push(newBoard);
                    visited.insert(newBoard);
                }
            }
        }
        return -1;
    }
};