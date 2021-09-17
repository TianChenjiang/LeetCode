class Solution {
public:
    const int N = 10;
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        // unordered_map<int, set<char>> row; //横
        // unordered_map<int, set<char>> col;
        // unordered_map<int, set<char>> grid;
        bool row[N][N]; 
        bool col[N][N]; 
        bool grid[N][N];
        memset(row, 0 ,sizeof(row));
        memset(col, 0 ,sizeof(col));
        memset(grid, 0 ,sizeof(grid));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int b = board[i][j] - '0';
                if (board[i][j] == '.') continue;
                int ind = (i / 3) * 3  + j / 3;
                if (row[i][b] || col[j][b] || grid[ind][b]) return false;
                row[i][b] = true;
                col[j][b] = true;
                grid[ind][b] = true;
            }
        }
        return true;
    }
};