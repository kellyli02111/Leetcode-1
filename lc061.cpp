//数有多少个node最好用一个单独的函数
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0) return head;
        ListNode* cur = head;
        int length = 1;
        while(cur->next != NULL){
            cur = cur->next;
            length++;
        }
        cur->next = head;
        ListNode* res = head;
        for(int i = 0; i < length - (k % length); i++){
            res = res->next;
            cur = cur->next;
        }
        cur->next = NULL;
        return res;
    }
};
