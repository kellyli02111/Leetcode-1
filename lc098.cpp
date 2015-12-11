class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        int pre = INT_MIN;
        bool firstNode = true;
        while(!st.empty() || cur != NULL){
            if(cur != NULL){
                st.push(cur);
                cur = cur->left;
            }
            else{
                cur = st.top();
                if(cur->val <= pre && firstNode == false){
                    return false;
                }
                pre = cur->val;
                firstNode = false;
                st.pop();
                cur = cur->right;
            }
        }
        return true;
    }
};
