class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        if(s.size() == 0) return true;
        unordered_map<char, char> um_src;
        unordered_map<char, char> um_trg;
        for(int i = 0; i < s.size(); i++){
            if(um_src.find(s[i]) != um_src.end()){
                if(um_src[s[i]] != t[i]){
                    return false;
                }
            }
            else{
                um_src[s[i]] = t[i];
            }
            if(um_trg.find(t[i]) != um_trg.end()){
                if(um_trg[t[i]] != s[i]){
                    return false;
                }
            }
            else{
                um_trg[t[i]] = s[i];
            }
        }
        return true;
    }
};
