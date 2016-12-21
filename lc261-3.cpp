//union-find, 找是否有环，以及是否为连通图
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> uf(n, -1);
        for(int i = 0; i < edges.size(); i++){
            int a = findRoot(uf, edges[i].first);
            int b = findRoot(uf, edges[i].second);
            if(a == b) return false;
            uf[a] = b;
        }
        return edges.size() == n - 1;
    }
    
    int findRoot(vector<int>& uf, int i){
        while(uf[i] != -1){
            i = uf[i];
        }
        return i;
    }
};
