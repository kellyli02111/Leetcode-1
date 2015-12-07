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
        bool isDup = false;
        while(cur->next->next != NULL){
            if(cur->next->val == cur->next->next->val){
                isDup = true;
                curNum = cur->next->val;
                delete(cur->next);
                cur->next = cur->next->next;
                continue;
            }
            
            if(isDup == true && cur->next->val == curNum){
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
