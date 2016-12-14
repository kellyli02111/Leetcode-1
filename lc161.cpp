class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(m == n) return isOneModified(s, t);
        if(m == n + 1) return isOneDeleted(s, t);
        if(m + 1 == n) return isOneDeleted(t, s);
        return false;
    }
    
    bool isOneModified(string s, string t){
        bool modified = false;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != t[i]){
                if(modified) return false;
                modified = true;
            }
        }
        return modified;
    }
    bool isOneDeleted(string s, string t){
        bool oneDeleted = false;
        int i = 0;
        int j = 0;
        while(i < s.size() && j < t.size()){
            if(s[i] != t[j]){
                if(oneDeleted) return false;
                i++;
                oneDeleted = true;
            }
            else{
                i++;
                j++;
            }
        }
        return true;
    }
};
