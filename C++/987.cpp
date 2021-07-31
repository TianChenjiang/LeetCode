/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<int, map<int,vector<int>>> m;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root, 0, 0);
        for (auto column : m) {
            vector<int> cur;
            for (auto row : column.second) {
                vector<int> vec = row.second;
                sort(vec.begin(), vec.end());
                for (int v : vec) cur.push_back(v);
            }
            res.push_back(cur);
        }
        return res;
    }

    void dfs(TreeNode* root, int row, int col) {
        if (!root) return;
        m[col][row].push_back(root->val);
        dfs(root->left, row+1, col-1);
        dfs(root->right, row+1, col+1);
    }
};