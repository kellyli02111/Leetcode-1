class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<int> roots(n, 0);
        for(int i = 0 ; i < n; i++){
            roots[i] = i;
        }
        int res = n;
        for(int i = 0; i < edges.size(); i++){
            int root1 = getRoot(roots, edges[i].first);
            int root2 = getRoot(roots, edges[i].second);
            if(root1 != root2){
                roots[root1] = root2;
                res--;
            }
        }
        return res;
    }
    int getRoot(vector<int> roots, int i){
        while(roots[i] != i){
            roots[i] = roots[roots[i]];
            i = roots[i];
        }
        return i;
    }
};
