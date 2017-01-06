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
        return helper(root, NULL, 0);
    }
    
    int helper(TreeNode* root, TreeNode* p, int res){
        if(root == NULL) return res;
        if(p && (root->val == p->val + 1)){
            res++;
        }
        else{
            res = 1;
        }
        return max(res, max(helper(root->left, root, res), helper(root->right, root, res)));
    }
};
