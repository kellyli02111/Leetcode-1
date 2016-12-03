/*一个DP问题。定义possible[i] 为S字符串上[0,i]的子串是否可以被segmented by dictionary.

那么

possible[i] = true      if  S[0,i]在dictionary里面

                = true      if   possible[k] == true 并且 S[k+1,j]在dictionary里面， 0<k<i

               = false      if    no such k exist.
               */

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if(s.empty()) return false;
        string s2 = '#' + s;
        int n = s2.size();
        vector<bool> dp(n, false);
        dp[0] = true;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                dp[i] = dp[j] && (wordDict.find(s2.substr(j + 1, i - j)) != wordDict.end());
                if(dp[i]) break;
            }
        }
        return dp[n - 1];
    }
};
