//easy recursive, cannot pass large test case
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2) return true;
        if(s1.size() != s2.size()) return false;
        for(int i = 1; i < s1.size(); i++){
            string s1Left = s1.substr(0, i);
            string s1Right = s1.substr(i);
            string s2Left = s2.substr(0, i);
            string s2Right = s2.substr(i);
            if(isScramble(s1Left, s2Left) && isScramble(s1Right, s2Right)) return true;
            if(isScramble(s1Left, s2Right) && isScramble(s1Right, s2Left)) return true;
        }
        return false;
    }
};
