class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        int temp;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(root);
        while(!q1.empty()){
            TreeNode* cur = q1.front();
            q1.pop();
            temp = cur->val;
            if(cur->left != NULL){
                q2.push(cur->left);
            }
            if(cur->right != NULL){
                q2.push(cur->right);
            }
            if(q1.empty()){
                res.push_back(temp);
                swap(q1, q2);
            }
        }
        return res;
    }
};
