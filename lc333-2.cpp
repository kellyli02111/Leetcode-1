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
    int largestBSTSubtree(TreeNode* root) {
        if(!root) return 0;
        int minVal = INT_MIN;
        int maxVal = INT_MAX;
        int res = 0;
        bool b = isValid(root, minVal, maxVal, res);
        return res;
    }
    
    bool isValid(TreeNode* root, int& minVal, int& maxVal, int& nodeCount){
        if(!root) return true;
        int leftNodeCount = 0;
        int rightNodeCount = 0;
        int leftMin = INT_MIN;
        int leftMax = INT_MAX;
        int rightMin = INT_MIN;
        int rightMax = INT_MAX;
        bool leftValid = isValid(root->left, leftMin, leftMax, leftNodeCount);
        bool rightValid = isValid(root->right, rightMin, rightMax, rightNodeCount);
        if(leftValid && rightValid){
            if((!root->left || root->val > leftMax) && (!root->right || root->val < rightMin)){
                nodeCount = leftNodeCount + rightNodeCount + 1;
                if(root->left){
                    minVal = leftMin;
                }
                else{
                    minVal = root->val;
                }
                if(root->right){
                    maxVal = rightMax;
                }
                else{
                    maxVal = root->val;
                }
                return true;
            }
        }
        nodeCount = max(leftNodeCount, rightNodeCount);
        return false;
    }
};
