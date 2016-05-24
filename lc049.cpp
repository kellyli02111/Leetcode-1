class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        for(int i = 0; i < strs.size(); i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            mp[temp].push_back(strs[i]);
        }
        for(auto it = mp.begin(); it != mp.end(); it++){
            sort(it->second.begin(), it->second.end());
            res.push_back(it->second);
        }
        return res;
    }
};
