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
    vector<int> res;
    int getDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int left = getDepth(root->left);
        int right = getDepth(root->right);
        return (left >= right) ? left + 1 : right + 1;
    }
    
    void levelOrder(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        int depth = getDepth(root);
        int cnt;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty() && cnt <= depth) {
            cnt++;
            int currentLevelSize = q.size();
            for (int i = 0; i < currentLevelSize; i++) {
                TreeNode* node = q.front(); q.pop();
                res.push_back(node->val);

                if (node->left) {
                    q.push(node->left);
                }
                else q.push(new TreeNode(-1));
                
                if (node->right) {
                    q.push(node->right);
                } 
                else q.push(new TreeNode(-1));
            }
        }
    }
    bool isSymmetric(TreeNode* root) {
        levelOrder(root);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << endl;
        }
        return true;
    }
};