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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        inorder(root, res, k, target);
        return res;
    }
    
    void inorder(TreeNode* root, vector<int>& vec, int k, double target){
        if(root == NULL) return;
        inorder(root->left, vec, k, target);
        if(vec.size() < k){
            vec.push_back(root->val);
        }
        else{
            if(abs(root->val - target) < abs(vec[0] - target)){
                vec.erase(vec.begin());
                vec.push_back(root->val);
            }
            else{
                return;
            }
        }
        inorder(root->right, vec, k, target);
    }
};
