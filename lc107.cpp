class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        vector<int> res_temp;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            if(cur == NULL){
                res.push_back(res_temp);
                res_temp.clear();
                if(q.empty()) break;
                q.push(NULL);
            }
            else{
                res_temp.push_back(cur->val);
                if(cur->left != NULL){
                    q.push(cur->left);
                }
                if(cur->right != NULL){
                    q.push(cur->right);
                }
            }
        }
        reverse(res.begin(), res.end());
    }
};
