class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* bef = &dummy;
        ListNode* cur = head;
        ListNode* move;
        while(cur != NULL && cur->next != NULL){
            move = cur->next;
            if(move->val < dummy.next->val){
                cur->next = move->next;
                move->next = dummy.next;
                dummy.next = move;
                continue;
            }
            bef = dummy.next;
            while(bef != cur){
                if(bef->next->val > move->val){
                    cur->next = move->next;
                    move->next = bef->next;
                    bef->next = move;
                    break;
                }
                else{
                    bef = bef->next;
                }
            }
            if(bef == cur){
                cur = cur->next;
            }
        }
        return dummy.next;
    }
};
