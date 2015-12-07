//不要先删node再引用它的next, 要用temp先存，有可能可以用但是有risk被改掉。delete了之后其他process可以对其进行改动。
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* cur = &dummy;
        while(cur->next != NULL){
            if(cur->next->val == val){
                delete(cur->next);
                cur->next = cur->next->next;
            }
            else{
                cur = cur->next;
            }
        }
        return dummy.next;
    }
};
