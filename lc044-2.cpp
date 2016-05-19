class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        int indexS = 0;
        int indexP = 0;
        int preS = 0;
        int preP = 0;
        bool star = false;
        while(indexS < m){
            if((indexP < n) && charMatch(s[indexS], p[indexP])){
                indexS++;
                indexP++;
            }
            else if(p[indexP] == '*'){
                while(p[indexP] == '*') indexP++;
                if(indexP == n) return true;
                preS = indexS;
                preP = indexP;
                star = true;
            }
            else if(star){
                preS++;
                indexS = preS;
                indexP = preP;
            }
            else{
                return false;
            }
        }
        while(p[indexP] == '*') indexP++;
        if((indexS == m) && (indexP == n)) return true;
        return false;
    }
    
    bool charMatch(char c, char p){
        return ((c == p) || p == '?');
    }
};
