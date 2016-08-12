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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> record;
        pathSumSub(root, sum, res, record);
        return res;
    }
    
    void pathSumSub(TreeNode* root, int sum, vector<vector<int>>& res, vector<int> record){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL){
            if(root->val == sum){
                record.push_back(root->val);
                res.push_back(record);
            }
            return;
        }
        record.push_back(root->val);
        pathSumSub(root->left, sum - root->val, res, record);
        pathSumSub(root->right, sum - root->val, res, record);
    }
};
