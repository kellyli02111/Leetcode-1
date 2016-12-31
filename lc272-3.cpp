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
        stack<TreeNode*> stk;
        TreeNode* node = root;
        while(node || !stk.empty()){
            while(node){
                stk.push(node);
                node = node->left;
            }
            node = stk.top();
            stk.pop();
            if(vec.size() < k){
                vec.push_back(node->val);
            }
            else{
                if(abs(node->val - target) < abs(vec[0] - target)){
                    vec.erase(vec.begin());
                    vec.push_back(node->val);
                }
                else{
                    break;
                }
            }
            node = node->right;
        }
    }
};
