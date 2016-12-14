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
        if(root == NULL) return NULL;
        TreeNode* cur = root;
        while(cur->left != NULL){
            TreeNode* leftChild = cur->left;
            TreeNode* rightChild = cur->right;
            cur->left = leftChild->left;
            cur->right = leftChild->right;
            leftChild->left = rightChild;
            leftChild->right = root;
            root = leftChild;
        }
        return root;
    }
};
