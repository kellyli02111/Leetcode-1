/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //O(n) space solution
class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> nodeList;
        vector<int> valList;
        inOrderTraversal(root, nodeList, valList);
        sort(valList.begin(), valList.end());
        for(int i = 0; i < nodeList.size(); i++){
            nodeList[i]->val = valList[i];
        }
        return;
    }
    
    void inOrderTraversal(TreeNode* node, vector<TreeNode*>& nodeList, vector<int>& valList){
        if(node == NULL) return;
        inOrderTraversal(node->left, nodeList, valList);
        nodeList.push_back(node);
        valList.push_back(node->val);
        inOrderTraversal(node->right, nodeList, valList);
    }
};
