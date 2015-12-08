//循环
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        TreeNode* cur = root;
        stack<TreeNode*> nodes;
        while(!nodes.empty() || cur != NULL){
            if(cur != NULL){
                nodes.push(cur);
                cur = cur->left;
            }
            else{
                cur = nodes.top();
                nodes.pop();
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }
};
