class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if((head == NULL) || (head->next == NULL)){
            return head;
        }
        ListNode* start = head;
        while ((start != NULL) && (start->next != NULL)){
            while((start->next != NULL) && (start->val == start->next->val)){
                start->next = start->next->next;
            }
            start = start->next;
        }
        return head;
    }
};
//在有loop的linked list里，每一层loop都要小心本层loop里会改动的指针，避免引用null的field.
