class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        stack<TreeNode*> cur;
        stack<TreeNode*> next;
        cur.push(root);
        TreeNode* temp;
        while(!cur.empty()){
            temp = cur.top();
            cur.pop();
            next.push(temp);
            if(temp->left != NULL){
                cur.push(temp->left);
            }
            if(temp->right != NULL){
                cur.push(temp->right);
            }
        }
        while(!next.empty()){
            res.push_back(next.top()->val);
            next.pop();
        }
        return res;
    }
};
