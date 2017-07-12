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
    int largestBSTSubtree(TreeNode* root) {
        if(!root) return 0;
        if(isValid(root, INT_MIN, INT_MAX)) return nodeCount(root);
        return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
    }
    
    bool isValid(TreeNode* root, int minVal, int maxVal){
        if(!root) return true;
        if(root->val <= minVal || root->val >= maxVal) return false;
        return isValid(root->left, minVal, root->val) && isValid(root->right, root->val, maxVal);
    }
    int nodeCount(TreeNode* root){
        if(!root) return 0;
        return nodeCount(root->left) + nodeCount(root->right) + 1;
    }
};
