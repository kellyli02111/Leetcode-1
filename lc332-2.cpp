class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, multiset<string>> um;
        vector<string> res;
        if(tickets.empty()) return res;
        for(auto i = tickets.begin(); i != tickets.end(); i++){
            um[i->first].insert(i->second);
        }
        
        stack<string> dfs;
        dfs.push("JFK");
        while(!dfs.empty()){
            string cur = dfs.top();
            if(um[cur].empty()){
                res.push_back(cur);
                dfs.pop();
            }
            else{
                dfs.push(*(um[cur].begin()));
                um[cur].erase(um[cur].begin());
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
