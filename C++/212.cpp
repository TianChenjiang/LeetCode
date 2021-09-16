class Solution {
public:
    struct TrieNode {
        TrieNode *child[26];
        string str;
    };
    struct Trie {
        TrieNode *root;
        Trie() : root(new TrieNode()) {}
        void insert(string s) {
            TrieNode *p = root;
            for (auto &a : s) {
                int i = a - 'a';
                if (!p->child[i]) p->child[i] = new TrieNode();
                p = p->child[i];
            }
            p->str = s;
        }
    };
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if (words.empty() || board.empty() || board[0].empty()) return res;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        Trie T;
        for (auto &word : words) {
            T.insert(word);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int cur = board[i][j] - 'a';
                if (T.root->child[cur]) {
                    dfs(board, T.root->child[cur], i, j, visited, res);
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& board, TrieNode* p, int i, int j, vector<vector<bool>>& visited, vector<string>& res) {
        if (!p->str.empty()) {
            res.push_back(p->str);
            p->str.clear();
        }
        visited[i][j] = true;
        int dirs[][2]  = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        for (auto& dir : dirs) {
            int nx = i + dir[0], ny = j + dir[1];
            if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size()) continue;
            if (visited[nx][ny]) continue;
            int u = board[nx][ny] - 'a';
            if (p->child[u]) {
                // visited[nx][ny] = true;
                dfs(board, p->child[board[nx][ny] - 'a'], nx, ny, visited, res);
                // visited[nx][ny] = false;
            }
        }
        visited[i][j] = false;
    }
};