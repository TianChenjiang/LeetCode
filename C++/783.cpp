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
    int minDiffInBST(TreeNode* root) {
        vector<int> vals;
        helper(root, vals);
        int res = INT_MAX;
        for (int i = 1; i < vals.size(); i++) {
            res = min(res, vals[i] - vals[i-1]);
        }
        return res;    
    }
    void helper(TreeNode* root, vector<int>& vals) {
        if (!root) return;
        helper(root->left, vals);
        vals.push_back(root->val);
        helper(root->right, vals);
    }
};