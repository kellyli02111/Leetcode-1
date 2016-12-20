//dfs, 找是否有环，以及是否为连通图
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> g(n, vector<int>());
        vector<bool> visited(n, false);
        for(int i = 0; i < edges.size(); i++){
            g[edges[i].first].push_back(edges[i].second);
            g[edges[i].second].push_back(edges[i].first);
        }
        if(!dfs(g, visited, 0, -1)) return false;
        for(int i = 0; i < n; i++){
            if(!visited[i]) return false;
        }
        return true;
    }
    
    bool dfs(vector<vector<int>>& g, vector<bool>& visited, int cur, int pre){
        if(visited[cur]) return false;
        visited[cur] = true;
        for(int i = 0; i < g[cur].size(); i++){
            if(g[cur][i] == pre) continue;
            if(!dfs(g, visited, g[cur][i], cur)) return false;
        }
        return true;
    }
};
