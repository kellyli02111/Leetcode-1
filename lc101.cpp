class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL|| (root->left == NULL && root->right == NULL)) return true;
        if(root->left == NULL || root->right == NULL) return false;
        return isMirroredSameTree(root->left, root->right);
    }
     bool isMirroredSameTree(TreeNode* p, TreeNode* q) {
        if((p == NULL && q != NULL) || (p != NULL && q == NULL)){
            return false;
        }
        if(p == NULL && q == NULL){
            return true;
        }
        return (p->val == q->val && isMirroredSameTree(p->left, q->right) && isMirroredSameTree(p->right, q->left));
    }
};
