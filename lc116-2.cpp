class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) return;
        TreeLinkNode* cur = root;
        TreeLinkNode* nextHead = NULL;
        TreeLinkNode* nextTail = NULL;
        while(cur != NULL){
            if(cur->left != NULL){
                if(nextHead == NULL){
                    nextHead = cur->left;
                    nextTail = cur->left;
                }
                else{
                    nextTail->next = cur->left;
                    nextTail = nextTail->next;
                }
            }
            if(cur->right != NULL){
                if(nextHead == NULL){
                    nextHead = cur->right;
                    nextTail = cur->right;
                }
                else{
                    nextTail->next = cur->right;
                    nextTail = nextTail->next;
                }
            }
            cur = cur->next;
            if(cur == NULL){
                cur = nextHead;
                nextHead = NULL;
                nextTail = NULL;
            }
        }
    }
};
