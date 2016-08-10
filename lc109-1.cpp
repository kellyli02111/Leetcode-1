/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* cur = head;
        int count = 0;
        while(cur != NULL){
            count++;
            cur = cur->next;
        }
        return sortedListToBST(head, 0, count - 1);
    }
    
    TreeNode* sortedListToBST(ListNode*& head, int start, int end){
        if(start > end) return NULL;
        int mid = start + (end - start) / 2;
        TreeNode* leftNode = sortedListToBST(head, start, mid - 1);
        TreeNode* rootNode = new TreeNode(head->val);
        head = head->next;
        TreeNode* rightNode = sortedListToBST(head, mid + 1, end);
        rootNode->left = leftNode;
        rootNode->right = rightNode;
        return rootNode;
    }
};
