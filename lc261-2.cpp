//bfs, 找是否有环，以及是否为连通图
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<unordered_set<int>> g(n, unordered_set<int>());
        unordered_set<int> visited;
        for(auto it = edges.begin(); it != edges.end(); it++){
            g[it->first].insert(it->second);
            g[it->second].insert(it->first);
        }
        queue<int> q;
        q.push(0);
        visited.insert(0);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto it = g[cur].begin(); it != g[cur].end(); it++){
                if(visited.find(*it) != visited.end()) return false;
                q.push(*it);
                visited.insert(*it);
                g[*it].erase(cur);
            }
        }
        return visited.size() == n;
    }
};
