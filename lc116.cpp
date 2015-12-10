class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) return;
        TreeLinkNode* start = root;
        while(start->left != NULL){
            TreeLinkNode* cur = start;
            TreeLinkNode* lastRight = NULL;
            while(cur!= NULL){
                cur->left->next = cur->right;
                if(lastRight != NULL){
                    lastRight->next = cur->left;
                }
                lastRight = cur->right;
                cur = cur->next;
            }
            start = start->left;
        }
    }
};
