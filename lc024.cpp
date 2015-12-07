//注意：如果ListNode* 不设初始值的话，默认值为不确定，并不是NULL。
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if((head == NULL) || (head->next == NULL)){
            return head;
        }
        ListNode dummy(0);
        dummy.next = head;
        ListNode* bef = &dummy;
        ListNode* cur = dummy.next;
        ListNode* move;
        while((cur != NULL) && (cur->next != NULL)){
            move = cur->next;
            cur->next = move->next;
            move->next = bef->next;
            bef->next = move;
            bef = cur;
            cur = cur->next;
        }
        return dummy.next;
    }
};
