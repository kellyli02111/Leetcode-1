class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string res = strs[0];
        for(int i = 0; i < strs.size(); i++){
            res = twoCommonPrefix(res, strs[i]);
        }
        return res;
    }
    string twoCommonPrefix(string s1, string s2){
        string res = "";
        int strLength = min(s1.size(), s2.size());
        for(int i = 0; i < strLength; i++){
            if(s1[i] != s2[i]){
                res = s1.substr(0, i);
                return res;
            }
        }
        return s1.substr(0, strLength);
    }   
    /*string twoCommonPrefix(string s1, string s2){
        string res = "";
        int strLength = min(s1.size(), s2.size());
        for(int i = 0; i < strLength; i++){
            if(s1[i] == s2[i]){
                res = res + s1[i];
            }
            else break;
        }
        return res;
    }*/
};
