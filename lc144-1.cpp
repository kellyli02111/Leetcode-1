//递归
//递归的时候的stack会存储函数的完整信息，数据量要远大于只用一个stack来存TreeNode。
//所以在时间空间上递归会比循环差。
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
