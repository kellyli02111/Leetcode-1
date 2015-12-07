class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode dummy(0);
        dummy.next = head;
        ListNode* cur = &dummy;
        int curNum;
        while(cur->next->next != NULL){
            if(cur->next->val == cur->next->next->val){
                curNum = cur->next->val;
                delete(cur->next);
                cur->next = cur->next->next;
                continue;
            }
            
            if(cur->next->val == curNum){
                delete(cur->next);
                cur->next = cur->next->next;
                continue;
            }
            cur = cur->next;
        }
        if(cur->next->val == curNum){
            delete(cur->next);
            cur->next = cur->next->next;
        }
        
        return dummy.next;
    }
};
