/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // preorder[pl, pr] 表示当前子树的前序遍历
    // inorder[il, ir] 表示当前子树的中序遍历
    TreeNode* work(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir) {
        if (pl > pr) return NULL;
        TreeNode* root = new TreeNode(preorder[pl]);
        for (int i = il; i <= ir; i++) {
            if (root->val == inorder[i]) { //i表示根的位置
                root->left = work(preorder, inorder, pl+1, pl+i-il, il, i-1); // 左子树的前序和中序
                root->right = work(preorder, inorder, pl+i-il+1, pr, i+1, ir); // 右子树的前序和中序
            }
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return work(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};