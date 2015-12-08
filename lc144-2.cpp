//蛋疼的循环写法
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        stack<TreeNode*> nodes;
        nodes.push(root);
        res.push_back(root->val);
        TreeNode* cur = root->left;
        while(!nodes.empty() || cur != NULL){
            if(cur == NULL){
                cur = nodes.top();
                nodes.pop();
                cur = cur->right;
            }
            else{
                res.push_back(cur->val);
                nodes.push(cur);
                cur = cur->left;
            }
        }
        return res;
    }
};
