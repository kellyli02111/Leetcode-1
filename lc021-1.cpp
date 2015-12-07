//递归：
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL){
            return l2;
        }
        if (l2 == NULL){
            return l1;
        }
        if(l1->val < l2->val){
            ListNode* newList = l1;
            newList->next = mergeTwoLists(l1->next, l2);
            return newList;
        }
        else{
            ListNode* newList = l2;
            newList->next = mergeTwoLists(l1, l2->next);
            return newList;
        }
    }
};
