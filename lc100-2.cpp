//非递归
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL || q == NULL){
            if(p == NULL && q == NULL) return true;
            return false;
        }
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        st1.push(p);
        st2.push(q);
        while(!st1.empty() && !st2.empty()){
            TreeNode* node1 = st1.top();
            TreeNode* node2 = st2.top();
            if(node1->val != node2->val) return false;
            st1.pop();
            st2.pop();
            if(node1->left != NULL || node2->left != NULL){
                if(node1->left != NULL && node2->left != NULL){
                    st1.push(node1->left);
                    st2.push(node2->left);
                }
                else{
                    return false;
                }
            }
            if(node1->right != NULL || node2->right != NULL){
                if(node1->right != NULL && node2->right != NULL){
                    st1.push(node1->right);
                    st2.push(node2->right);
                }
                else{
                    return false;
                }
            }
        }
        if(!st1.empty()|| !st2.empty()) return false;
        return true;
    }
};
