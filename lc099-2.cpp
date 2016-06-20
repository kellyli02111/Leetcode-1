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
    void recoverTree(TreeNode* root) {
        if(root == false) return;
        bool found = false;
        TreeNode* f1 = NULL;
        TreeNode* f2 = NULL;
        TreeNode* cur = root;
        TreeNode* parent = NULL;
        TreeNode* pre;
        while(cur != NULL){
            if(cur->left == NULL){
                if(parent != NULL && parent->val > cur->val){
                    if(!found){
                        f1 = parent;
                        found = true;
                    }
                    f2 = cur;
                }
                parent = cur;
                cur = cur->right;
            }
            else{
                pre = cur->left;
                while(pre->right != NULL && pre->right != cur){
                    pre = pre->right;
                }
                if(pre->right == NULL){
                    pre->right = cur;
                    cur = cur->left;
                }
                else{
                    pre->right = NULL;
                    if(parent->val > cur->val){
                        if(!found){
                            f1 = parent;
                            found = true;
                        }
                        f2 = cur;
                    }
                    parent = cur;
                    cur = cur->right;
                }
            }
        }
        if(f1 && f2){
            swap(f1->val, f2->val);
        }
    }
};
