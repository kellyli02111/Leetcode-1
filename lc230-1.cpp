class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL) return 0;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        int count = 0;
        while(!st.empty() || cur != NULL){
            if(cur != NULL){
                st.push(cur);
                cur = cur->left;
            }
            else{
                cur = st.top();
                st.pop();
                count++;
                if(count == k){
                    return cur->val;
                }
                cur = cur->right;
            }
        }
    }
};
