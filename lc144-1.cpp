//递归
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        preorderTraversal_sub(root, res);
        return res;
    }
    void preorderTraversal_sub(TreeNode* root, vector<int>& vecIn) {
        if(root == NULL) return;
        vecIn.push_back(root->val);
        preorderTraversal_sub(root->left, vecIn);
        preorderTraversal_sub(root->right, vecIn);
    }
};
