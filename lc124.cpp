/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxAcrossRoot = INT_MIN;
        int maxTopRoot = getMax(root, maxAcrossRoot);
        return max(maxTopRoot, maxAcrossRoot);
    }
    int getMax(TreeNode* node, int& maxAcrossRoot){
        if(node == NULL) return 0;
        int leftMax = getMax(node->left, maxAcrossRoot);
        int rightMax = getMax(node->right, maxAcrossRoot);
        int cMax = node->val;
        if(leftMax > 0){
            cMax = cMax + leftMax;
        }
        if(rightMax > 0){
            cMax = cMax + rightMax;
        }
        maxAcrossRoot = max(maxAcrossRoot, cMax);
        return max(node->val, max(node->val + leftMax, node->val + rightMax));
    }
};
