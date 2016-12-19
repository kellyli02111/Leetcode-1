class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> res;
        unordered_map<string, multiset<string>> um;
        for(int i = 0; i < strings.size(); i++){
            string feature = "";
            for(int j = 1; j < strings[i].size(); j++){
                char t = (strings[i][j] -strings[i][j - 1] + 26) % 26;
                feature = feature + to_string(t) + ",";
            }
            um[feature].insert(strings[i]);
        }
        for(auto it = um.begin(); it != um.end(); it++){
            vector<string> cur;
            multiset<string> ms = it->second;
            for(auto it2 = ms.begin(); it2 != ms.end(); it2++){
                cur.push_back(*it2);
            }
            res.push_back(cur);
        }
        return res;
    }
};
