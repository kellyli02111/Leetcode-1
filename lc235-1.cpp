class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || p == root || q == root) return root;
        TreeNode* leftRes = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightRes = lowestCommonAncestor(root->right, p, q);
        if(leftRes != NULL && rightRes != NULL) return root;
        if(leftRes == NULL) return rightRes;
        if(rightRes == NULL) return leftRes;
    }
};
