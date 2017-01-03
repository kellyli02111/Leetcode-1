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
        if(root == NULL) return NULL;
        if(root->val <= p->val){
            return inorderSuccessor(root->right, p);
        }
        else{
            TreeNode* temp = inorderSuccessor(root->left, p);
            if(temp){
                return temp;
            }
            return root;
        }
    }
};
