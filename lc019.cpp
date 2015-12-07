//delete(node) 很重要，不用的一定删掉。

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* cur = &dummy;
        ListNode* del = cur->next;
        for(int i = 0; i < n - 1; i++){
            del = del->next;
        }
        ListNode* bef = &dummy;
        while(del != NULL){
            bef = cur;
            cur = cur->next;
            del = del->next;
        }
        bef->next = cur->next;
        delete(cur);
        return dummy.next;
    }
};
