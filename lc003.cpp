class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        bool charExist[256];
        memset(charExist, false, sizeof(charExist));
        int res = 0;
        int start = 0;
        int end = 0;
        while(start < n && end < n){
            if(charExist[s[end]] == false){
                charExist[s[end]] = true;
                end++;
            }
            else{
                charExist[s[start]] = false;
                start++;
            }
            res = max(res, end - start);
        }
        return res;
    }
};
