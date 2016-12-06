class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        if(s.size() == 0) return true;
        return (isIsomorphicHelper(s, t) && isIsomorphicHelper(t, s));
    }
    bool isIsomorphicHelper(string s, string t){
        int n = s.size();
        bool mem[n];
        memset(mem, false, sizeof(mem));
        for(int i = 0; i < s.size(); i++){
            if(mem[i]) continue;
            mem[i] = true;
            for(int j = i; j < s.size(); j++){
                if(s[i] == s[j]){
                    if(t[i] == t[j]){
                        mem[j] = true;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
