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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> res1, res2;
        getLeafSeq(res1, root1);
        getLeafSeq(res2, root2);
        return res1 == res2;
    }

    void getLeafSeq(vector<int> &res, TreeNode* cur) {
        if (!cur->left && !cur->right) res.push_back(cur->val);
        if (cur->left) getLeafSeq(res, cur->left);
        if (cur->right) getLeafSeq(res, cur->right);
    }
};