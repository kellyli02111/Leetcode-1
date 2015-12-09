//两个queue的做法
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> res_temp;
        if(root == NULL) return res;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(root);
        while(!q1.empty()){
            TreeNode* temp = q1.front();
            q1.pop();
            res_temp.push_back(temp->val);
            if(temp->left != NULL){
                q2.push(temp->left);
            }
            if(temp->right != NULL){
                q2.push(temp->right);
            }
            if(q1.empty()){
                res.push_back(res_temp);
                res_temp.clear();
                swap(q1, q2);
            }
        }
        return res;
    }
};
