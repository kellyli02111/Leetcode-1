//递归
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        postorderTraversal_sub(root, res);
        return res;
    }
    
    void postorderTraversal_sub(TreeNode* root, vector<int>& vecIn) {
        if(root == NULL) return;
        postorderTraversal_sub(root->left, vecIn);
        postorderTraversal_sub(root->right, vecIn);
        vecIn.push_back(root->val);
    }
};
