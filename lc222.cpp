class Solution {
public:
    int getLeftDepth(TreeNode* root){
        if(root == NULL) return 0;
        int res = 0;
        while(root != NULL){
            res++;
            root = root->left;
        }
        return res;
    }
    int getRightDepth(TreeNode* root){
        if(root == NULL) return 0;
        int res = 0;
        while(root != NULL){
            res++;
            root = root->right;
        }
        return res;
    }
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int leftDepth = getLeftDepth(root);
        int rightDepth = getRightDepth(root);
        if(leftDepth == rightDepth){
            return (1<<leftDepth) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
