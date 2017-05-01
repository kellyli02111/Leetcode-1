class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> adjList(n);
        vector<bool> visited(n, false);
        for(int i = 0; i < edges.size(); i++){
            adjList[edges[i].first].push_back(edges[i].second);
            adjList[edges[i].second].push_back(edges[i].first);
        }
        int res = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                res++;
                dfs(adjList, visited, i);
            }
        }
        return res;
    }
    void dfs(vector<vector<int>>& adjList, vector<bool>& visited, int n){
        for(int i = 0; i < adjList[n].size(); i++){
            if(!visited[adjList[n][i]]){
                visited[adjList[n][i]] = true;
                dfs(adjList, visited, adjList[n][i]);
            }
        }
    }
};
