class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        stack<TreeNode*> st;
        st.push(root);
        TreeNode* cur;
        TreeNode* pre = NULL;
        while(!st.empty()){
            cur = st.top();
            if((cur->left == NULL && cur->right == NULL) || (pre && (cur->left == pre || cur->right == pre))){
                st.pop();
                res.push_back(cur->val);
                pre = cur;
            }
            else{
                if(cur->right != NULL){
                    st.push(cur->right);
                }
                if(cur->left != NULL){
                    st.push(cur->left);
                }
            }
        }
        return res;
    }
};
