class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if((head == NULL) || (head->next == NULL)){
            return head;
        }
        ListNode dummy(0);
        dummy.next = head;
        ListNode* cur = head;
        ListNode* move;
        while(cur->next != NULL){
            move = cur->next;
            cur->next = move->next;
            move->next = dummy.next;
            dummy.next = move;
        }
      return move;
    }
};
