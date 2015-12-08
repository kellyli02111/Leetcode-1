递归：
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return buildTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int preA, int preB, int inA, int inB) {
        if(preA > preB) return NULL;
        TreeNode* root = new TreeNode(preorder[preA]);
        if(preA == preB){
            return root;
        }
        int preIndex = 1;
        int inIndex = 0;
        while(inorder[inA + inIndex] != root->val){
            inIndex++;
            preIndex++;
            
        }
        root->left = buildTree(preorder, inorder, preA + 1, preA + preIndex - 1, inA, inA + inIndex - 1);
        root->right = buildTree(preorder, inorder, preA + preIndex, preB, inA + inIndex + 1, inB);
        return root;
    }
};
