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
    int longestConsecutive(TreeNode* root) {
        if(root == NULL) return 0;
        int res;
        dfs(root, root->val - 1, 0, res);
        return res;
    }
    
    void dfs(TreeNode* node, int prev, int len, int& res){
        if(node == NULL) return;
        if(node->val == prev + 1){
            len++;
        }
        else{
            len = 1;
        }
        res = max(res, len);
        dfs(node->left, node->val, len, res);
        dfs(node->right, node->val, len, res);
    }
};
