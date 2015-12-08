//正常人的preorder循环写法
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        stack<TreeNode*> nodes;
        nodes.push(root);
        TreeNode* cur = root;
        while(!nodes.empty()){
            cur = nodes.top();
            res.push_back(cur->val);
            nodes.pop();
            if(cur->right != NULL){
                nodes.push(cur->right);
            }
            if(cur->left != NULL){
                nodes.push(cur->left);
            }
        }
        return res;
    }
};
