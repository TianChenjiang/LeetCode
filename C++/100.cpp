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
    // 前序遍历
    vector<int> traverse(TreeNode* p, vector<int> &order) {
        if (p != NULL) {
            order.push_back(p->val);
            traverse(p->left, order);
            traverse(p->right, order);
        } else {
            order.push_back(NULL);
        }
        return order;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> order1, order2;
        traverse(p, order1);
        traverse(q, order2);
        
        return order1 == order2;
    } 
};