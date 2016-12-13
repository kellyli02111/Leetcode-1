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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root == NULL) return res;
        TreeNode* node = root;
        string cur = to_string(node->val);
        if(node->left == NULL && node->right == NULL){
            res.push_back(cur);
            return res;
        }
        if(node->left != NULL){
            dfs(node->left, res, cur);
        }
        if(node->right != NULL){
            dfs(node->right, res, cur);
        }
        return res;
    }
    
    void dfs(TreeNode* node, vector<string>& res, string cur){
        if(node->left == NULL && node->right == NULL){
            cur = cur + "->" + to_string(node->val);
            res.push_back(cur);
            return;
        }
        cur = cur + "->" + to_string(node->val);
        if(node->right == NULL){
            dfs(node->left, res, cur);
            return;
        }
        if(node->left == NULL){
            dfs(node->right, res, cur);
            return;
        }
        dfs(node->left, res, cur);
        dfs(node->right, res, cur);
    }
};
