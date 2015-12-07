class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL || (root->left == NULL && root->right == NULL)) return;
        flatten(root->left);
        flatten(root->right);
        if(root->left != NULL){
            TreeNode* leftNode = root->left;
            TreeNode* rightNode = root->right;
            while(leftNode->right != NULL){
                leftNode = leftNode->right;
            }
            leftNode->right= rightNode;
            root->right = root->left;
            root->left = NULL;
        }
    }
};
