class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* cur = head;
        ListNode* bef = &dummy;
        while(cur != NULL && cur->val < x){
            bef = cur;
            cur = cur->next;
        }
        while(cur != NULL && cur->next != NULL){
            if(cur->next->val < x){
                ListNode* move = cur->next;
                cur->next = move->next;
                move->next = bef->next;
                bef->next = move;
                bef = bef->next;
            }
            else{
                cur = cur->next;
            }
        }
        return dummy.next;
    }
};
