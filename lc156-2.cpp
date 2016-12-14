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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(root == NULL || root->left == NULL) return root;
        TreeNode* leftChild = root->left;
        TreeNode* rightChild = root->right;
        TreeNode* res = upsideDownBinaryTree(leftChild);
        leftChild->left = rightChild;
        leftChild->right = root;
        root->left = NULL;
        root->right = NULL;
        return res;
    }
};
