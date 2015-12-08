//递归
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return buildTree(inorder, postorder, 0, n - 1, 0, n - 1);
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int inA, int inB, int postA, int postB) {
        if(postA > postB) return NULL;
        TreeNode* root = new TreeNode(postorder[postB]);
        if(postA == postB){
            return root;
        }
        int inIndex = 0;
        int postIndex = 0;
        while(inorder[inA + inIndex] != root->val){
            inIndex++;
            postIndex++;
            
        }
        root->left = buildTree(inorder, postorder, inA, inA + inIndex - 1, postA, postA + postIndex - 1);
        root->right = buildTree(inorder, postorder, inA + inIndex + 1, inB, postA + postIndex, postB - 1);
        return root;
    }
};
