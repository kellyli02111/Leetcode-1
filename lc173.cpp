/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> stk;
    BSTIterator(TreeNode *root) {
        TreeNode* node = root;
        while(node){
            stk.push(node);
            node = node->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (!stk.empty());
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* cur =  stk.top();
        stk.pop();
        int res = cur->val;
        if(cur->right != NULL){
            stk.push(cur->right);
            cur = cur->right;
            while(cur->left != NULL){
                stk.push(cur->left);
                cur = cur->left;
            }
        }
        return res;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
