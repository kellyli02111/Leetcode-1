class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        int carry = 0;
        ListNode dummy(0);
        ListNode* res = &dummy;
        while(l1 != NULL || l2 != NULL || carry != 0){
            if(l1 != NULL){
                carry = carry + l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                carry = carry + l2->val;
                l2 = l2->next;
            }
            ListNode* tempNode = new ListNode(carry % 10);
            res->next = tempNode;
            res = res->next;
            carry = carry / 10;
        }
        return dummy.next;
    }
};
