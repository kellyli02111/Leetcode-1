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
    int countUnivalSubtrees(TreeNode* root) {
        if(root == NULL) return 0;
        int res;
        bool isUnivalue = countRec(root, res);
        return res;
    }
    
    bool countRec(TreeNode* root, int& res){
        cout<<root->val<<endl;
        bool leftUnivalue;
        bool rightUnivalue;
        if(root->left){
            leftUnivalue = countRec(root->left, res);
        }
        if(root->right){
            rightUnivalue = countRec(root->right, res);
        }
        if(root->left && (!leftUnivalue || (root->val != root->left->val))){
            return false;
        }
        if(root->right && (!rightUnivalue || (root->val != root->right->val))){
            return false;
        }
        res++;
        return true;
    }
};
