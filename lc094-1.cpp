//递归
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        inorderTraversal_sub(root, res);
        return res;
    }
    void inorderTraversal_sub(TreeNode* root, vector<int>& vecIn) {
        if(root == NULL) return;
        inorderTraversal_sub(root->left, vecIn);
        vecIn.push_back(root->val);
        inorderTraversal_sub(root->right, vecIn);
    }
};
