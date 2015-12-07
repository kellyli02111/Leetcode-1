class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if((head == NULL) || (head->next == NULL) || (k == 1)){
            return head;
        }
        ListNode dummy(0);
        dummy.next = head;
        ListNode* bef = &dummy;
        ListNode* cur = dummy.next;
        ListNode* move;
        while((cur != NULL) && hasValue(cur, k - 1 )){
            for(int i = 0; i < k - 1; i++){
                move = cur->next;
                cur->next = move->next;
                move->next = bef->next;
                bef->next = move;
            }
            bef = cur;
            cur = cur->next;
        }
        return dummy.next;
    }
    
    bool hasValue(ListNode* head, int distance){
        ListNode* trace = head;
        for(int i = 0; i < distance; i++){
            trace = trace->next;
            if(trace == NULL){
                return false;
            }
        }
        return true;
    }
};
