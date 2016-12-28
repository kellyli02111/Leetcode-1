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
    int closestValue(TreeNode* root, double target) {
        TreeNode* child;
        if(root->val == target) return root->val;
        if(root->val < target){
            child = root->right;
        }
        else{
            child = root->left;
        }
        if(child == NULL) return root->val;
        int childVal = closestValue(child, target);
        if(abs(root->val - target) < abs(childVal - target)){
            return root->val;
        }
        return childVal;
    }
};
