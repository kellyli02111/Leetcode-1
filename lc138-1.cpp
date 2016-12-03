/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL) return NULL;
        unordered_map<RandomListNode*, RandomListNode*> randomMap;
        RandomListNode* dummy = new RandomListNode(0);
        RandomListNode* dummyCopy = new RandomListNode(0);
        dummy->next = head;

        RandomListNode* cur = dummy;
        RandomListNode* curCopy = dummyCopy;
        while(cur != NULL && cur->next != NULL){
            RandomListNode* newNode = new RandomListNode(cur->next->label);
            randomMap[cur->next] = newNode;
            curCopy->next = newNode;
            cur = cur->next;
            curCopy = curCopy->next;
        }
        cur = dummy;
        curCopy = dummyCopy;
        while(cur != NULL){
            curCopy->random = randomMap[cur->random];
            cur = cur->next;
            curCopy = curCopy->next;
        }
        return dummyCopy->next;
    }
};
