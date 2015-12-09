class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        int dir = 0;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        vector<int> res_temp;
        s1.push(root);
        while(!(s1.empty() && s2.empty())){
            TreeNode* temp = s1.top();
            res_temp.push_back(temp->val);
            s1.pop();
            if(dir == 0){
                if(temp->left != NULL){
                    s2.push(temp->left);
                }
                if(temp->right != NULL){
                    s2.push(temp->right);
                }
            }
            if(dir == 1){
                if(temp->right != NULL){
                    s2.push(temp->right);
                }
                if(temp->left != NULL){
                    s2.push(temp->left);
                }
            }
            if(s1.empty()){
                res.push_back(res_temp);
                res_temp.clear();
                swap(s1, s2);
                dir = 1 - dir;
            }
        }
        return res;
    }
};
