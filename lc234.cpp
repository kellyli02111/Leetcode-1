class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return true;
        }
        int count = 0;
        ListNode* cur = head;
        while(cur != NULL){
            count++;
            cur = cur->next;
        }
        ListNode* bef = head;
        for(int i = 0; i < count / 2 - 1; i++){
            bef = bef->next;
        }
        cur = bef->next;
        ListNode* move = cur;
        while(cur->next != NULL){
            move = cur->next;
            cur->next = move->next;
            move->next = bef->next;
            bef->next = move;
        }
        ListNode* l1 = head;
        ListNode* l2 = move;
        for(int i = 0; i < count / 2; i++){
            if(l1->val != l2->val) return false;
            else{
                l1 = l1->next;
                l2 = l2->next;
            }
        }
        return true;
    }
};
