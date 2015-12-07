class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        return (abs(maxDepth(root->left) - maxDepth(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right));
        
    }
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
