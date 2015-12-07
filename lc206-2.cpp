//另一种解法（用数组存储所有的地址）
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if((head == NULL) || (head->next == NULL)){
            return head;
        }
        ListNode* cur = head;
        vector<ListNode*> nodeAddr;
        while(cur != NULL){
            nodeAddr.push_back(cur);
            cur = cur->next;
        }
        int n = nodeAddr.size();
        for(int i = n - 1; i > 0; i--){
            nodeAddr[i]->next = nodeAddr[i - 1];
        }
        nodeAddr[0]->next = NULL;
        return nodeAddr[n - 1];
    }
};
