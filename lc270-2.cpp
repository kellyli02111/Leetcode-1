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
    int closestValue(TreeNode* root, double target) {
        TreeNode* cur = root;
        int res = root->val;;
        while(cur){
            if(cur->val == target) return cur->val;
            if(abs(res - target) > abs(cur->val - target)){
                res = cur->val;
            }
            if(cur->val < target){
                cur = cur->right;
            }
            else{
                cur = cur->left;
            }
        }
        return res;
    }
};
