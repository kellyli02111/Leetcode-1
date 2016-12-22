class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, bool> um;
        for(int i = 0; i < s.size(); i++){
            if(um.find(s[i]) == um.end()){
                um[s[i]] = true;
            }
            else{
                um[s[i]] = !um[s[i]];
            }
        }
        bool flag = false;
        for(auto it = um.begin(); it != um.end(); it++){
            if(flag == true && it->second == true) return false;
            if(it->second == true){
                flag = true;
            }
        }
        return true;
    }
};
