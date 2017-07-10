class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, multiset<string>> um;
        for(auto i = tickets.begin(); i != tickets.end(); i++){
            um[i->first].insert(i->second);
        }
        vector<string> res;
        dfs(um, "JFK", res);
        reverse(res.begin(), res.end());
        return res;
    }
    
    void dfs(unordered_map<string, multiset<string>>& um, string s, vector<string>& res){
        while(um[s].size()){
            string t = *um[s].begin();
            um[s].erase(um[s].begin());
            dfs(um, t, res);
        }
        res.push_back(s);
    }
};
