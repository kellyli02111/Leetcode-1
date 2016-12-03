/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 //http://fisherlei.blogspot.com/2013/11/leetcode-copy-list-with-random-pointer.html
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL) return NULL;
        RandomListNode* cur = head;
        while(cur != NULL){
            RandomListNode* temp = new RandomListNode(cur->label);
            temp->next = cur->next;
            cur->next = temp;
            cur = temp->next;
        }
        cur = head;
        while(cur != NULL){
            RandomListNode* temp = cur->next;
            if(cur->random != NULL){
                temp->random = cur->random->next;
            }
            cur = temp->next;
        }
        
        cur = head;
        RandomListNode* res = head->next;
        while(cur != NULL){
            RandomListNode* temp = cur->next;
            cur->next = temp->next;
            if(temp->next != NULL){
                temp->next = temp->next->next;
            }
            cur = cur->next;
        }
        return res;
    }
};
