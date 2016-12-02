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
    int sumNumbers(TreeNode* root) {
        int res = 0;
        int cur = 0;
        sumNumbers(root, res, cur);
        return res;
    }
    
    void sumNumbers(TreeNode* node, int& sum, int cur){
        if(node == NULL){
            return;
        }
        cur = cur * 10 + node->val;
        if(node->left == NULL && node->right == NULL){
            sum = sum + cur;
        }
        sumNumbers(node->left, sum, cur);
        sumNumbers(node->right, sum, cur);
    }
};
