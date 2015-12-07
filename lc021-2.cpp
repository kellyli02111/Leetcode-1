//非递归：
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL){
            return l2;
        }
        if (l2 == NULL){
            return l1;
        }
        ListNode dummy(0);
        ListNode* l1Cur = l1;
        ListNode* l2Cur = l2;
        ListNode* lastPtr = &dummy;
        while((l1Cur != NULL) && (l2Cur != NULL)){
            if(l1Cur->val < l2Cur->val){
                lastPtr->next = l1Cur;
                lastPtr = l1Cur;
                l1Cur = l1Cur->next;
            }
            else{
                lastPtr->next = l2Cur;
                lastPtr = l2Cur;
                l2Cur = l2Cur->next;
            }
        }
        if(l1Cur == NULL){
            lastPtr->next = l2Cur;
        }
        else{
            lastPtr->next = l1Cur;
        }
        return dummy.next;
    }
};
