class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if(n == 1) return {0};
        vector<int> res;
        vector<unordered_set<int>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i].first].insert(edges[i].second);
            adj[edges[i].second].insert(edges[i].first);
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(adj[i].size() == 1){
                q.push(i);
            }
        }
        while(n > 2){
            int qSize = q.size();
            n = n - qSize;
            for(int i = 0; i < qSize; i++){
                int cur = q.front();
                q.pop();
                for(auto a = adj[cur].begin(); a != adj[cur].end(); a++){
                    adj[*a].erase(cur);
                    if(adj[*a].size() == 1){
                        q.push(*a);
                    }
                }
            }
        }
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};
