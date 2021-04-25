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
private:
    TreeNode* dummy, *tmp;
public:
    TreeNode* increasingBST(TreeNode* root) {
        dummy = new TreeNode(-1);
        tmp = dummy;
        helper(root);
        return dummy->right;
    }

    void helper(TreeNode* root) {
        if (!root) return;
        if (root->left) helper(root->left);
        // 这里root要作为下一个节点
        
        tmp->right = root;
        root->left = nullptr;
        tmp = tmp->right;
        
        if (root->right) helper(root->right);
    }
};