class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        int countA = 0;
        int countB = 0;
        while(curA != NULL){
            countA++;
            curA = curA->next;
        }
        while(curB != NULL){
            countB++;
            curB = curB->next;
        }
        if(countA > countB){
            for(int i = 0; i < (countA - countB); i++){
                headA = headA->next;
            }
        }
        if(countB > countA){
            for(int i = 0; i < (countB - countA); i++){
                headB = headB->next;
            }
        }
        while(headA != headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA; // 如果没有intersect，那么最后NULL == NULL 判定通过，返回NULL
    }
};
