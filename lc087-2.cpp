class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        if(s1.size() == 0) return true;
        vector<vector<vector<bool>>>dp(s1.size(), vector<vector<bool>>(s1.size(), vector<bool>(s1.size() + 1, false)));
        for(int i = 0; i < s1.size(); i++){
            for(int j = 0; j < s1.size(); j++){
                dp[i][j][1] = (s1[i] == s2[j]);
            }
        }
        for(int len = 2; len <= s1.size(); len++){
            for(int i = 0; i < s1.size() + 1 - len; i++){
                for(int j = 0; j < s2.size() + 1 - len; j++){
                    for(int k = 1; k < len; k++){
                        dp[i][j][len] =  dp[i][j][len] || ((dp[i][j][k] && dp[i + k][j + k][len - k]) || (dp[i][j + len - k][k] && dp[i + k][j][len - k]));
                    }
                }
            }
        }
        return dp[0][0][s1.size()];
    }
};
