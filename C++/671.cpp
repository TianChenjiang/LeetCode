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
    int res = -1, minValue = -1;
    int findSecondMinimumValue(TreeNode* root) {
        minValue = root->val;
        findMiniumValue(root);
        return res;
    }

    void findMiniumValue(TreeNode* root) {
        if (root->val != minValue) {
            if (res == -1) res = root->val;
            else res = min(res, root->val);
        }
        if (!root->left) return;
        findMiniumValue(root->left);
        findMiniumValue(root->right);
    }

};