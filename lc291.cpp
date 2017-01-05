class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        unordered_map<char, string> um;
        unordered_set<string> us;
        return helper(pattern, str, 0, 0, um, us);
    }
    
    bool helper(string& pattern, string& str, int idx1, int idx2, unordered_map<char, string>& um, unordered_set<string>& us){
        if(idx1 == pattern.size() && idx2 == str.size()) return true;
        if(idx1 == pattern.size() || idx2 == str.size()) return false;
        char c = pattern[idx1];
        for(int i = idx2; i < str.size(); i++){
            string word = str.substr(idx2, i - idx2 + 1);
            if(um.find(c) != um.end()){
                if(um[c] == word){
                    if(helper(pattern, str, idx1 + 1, i + 1, um, us)) return true;
                }
                continue;
            }
            else{
                if(us.find(word) == us.end()){
                    um[c] = word;
                    us.insert(word);
                    if(helper(pattern, str, idx1 + 1, i + 1, um, us)) return true;
                    um.erase(c);
                    us.erase(word);
                }
                else{
                    continue;
                }
            }
        }
        return false;
    }
};
