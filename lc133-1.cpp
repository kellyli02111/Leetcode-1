/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL) return NULL;
        queue<UndirectedGraphNode*> q;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> nodeMap;
        q.push(node);
        UndirectedGraphNode* newNode = new UndirectedGraphNode(node->label);
        nodeMap[node] = newNode;
        while(!q.empty()){
            UndirectedGraphNode* curSource = q.front();
            UndirectedGraphNode* curCopy = nodeMap[curSource];
            q.pop();
            for(int i = 0; i < (curSource->neighbors).size(); i++){
                if(nodeMap.find(curSource->neighbors[i]) == nodeMap.end()){
                    q.push(curSource->neighbors[i]);
                    UndirectedGraphNode* temp = new UndirectedGraphNode(curSource->neighbors[i]->label);
                    nodeMap[curSource->neighbors[i]] = temp;
                    curCopy->neighbors.push_back(temp);
                }
                else{
                    UndirectedGraphNode* temp = nodeMap[curSource->neighbors[i]];
                    curCopy->neighbors.push_back(temp);
                }
            }
        }
        return newNode;
    }
};
