class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || p == root || q == root) return root;
        TreeNode* cur = root;
        int pVal = p->val;
        int qVal = q->val;
        while(true){
            if((cur->val <= pVal && cur->val >= qVal) || (cur->val >= pVal && cur->val <= qVal)) return cur;
            if(cur->val > pVal && cur->val > qVal) cur = cur->left;
            if(cur->val < pVal && cur->val < qVal) cur = cur->right;
        }
    }
};
