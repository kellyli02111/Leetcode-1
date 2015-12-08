//一个queue的做法
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> res_temp;
        if(root == NULL) return res;
        queue<TreeNode*> q1;
        q1.push(root);
        q1.push(NULL);
        while(!(q1.empty())){
            TreeNode* temp = q1.front();
            q1.pop();
            if(temp == NULL){
                res.push_back(res_temp);
                res_temp.clear();
                if(q1.empty()){
                    break;
                }
                q1.push(NULL);
            }
            else{
                res_temp.push_back(temp->val);
                if(temp->left != NULL){
                    q1.push(temp->left);
                }
                if(temp->right != NULL){
                    q1.push(temp->right);
                }
            }
        }
        return res;
    }
};
