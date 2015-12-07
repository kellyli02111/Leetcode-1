class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if((head == NULL) || (head->next == NULL) || (m == n)){
            return head;
        }
        ListNode dummy(0);
        dummy.next = head;
        ListNode* lastUnchanged = &dummy;
        for(int i = 0; i< m - 1; i++){
            lastUnchanged = lastUnchanged->next;
        }
        ListNode* cur = lastUnchanged->next;
        ListNode* move;
        for(int i = 0; i < n - m; i++){
            move = cur->next;
            cur->next = move->next;
            move->next = lastUnchanged->next;
            lastUnchanged->next = move;
        }
        return dummy.next;
    }
};
