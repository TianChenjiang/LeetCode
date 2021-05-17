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
    bool isCousins(TreeNode* root, int x, int y) {
        unordered_map<int, int> m;
        m[root->val] = 0;
        queue<TreeNode*> q({root});
        while (!q.empty()) {
            TreeNode* cur = q.front(); q.pop();
            if (cur->left) {
                q.push(cur->left);
                m[cur->left->val] = m[cur->val]+1;
            }
            if (cur->right) {
                q.push(cur->right);
                m[cur->right->val] = m[cur->val]+1;
            }
            if (cur->left && cur->right) {
                if (cur->left->val == x && cur->right->val == y || cur->left->val == y && cur->right->val == x) return false;
            }
        }
        return m[x] == m[y];
    }
};