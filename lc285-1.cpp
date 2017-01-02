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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* res = NULL;
        TreeNode* cur = root;
        while(cur){
            if(cur->val > p->val){
                res = cur;
                cur = cur->left;
            }
            else{
                cur = cur->right;
            }
        }
        return res;
    }
};
