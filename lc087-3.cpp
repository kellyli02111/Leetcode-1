class Solution {
private:
    bool isScrambleRecur(vector<vector<vector<int>>>& dp, string& s1, string& s2, int n1, int n2, int len) {
        if(dp[n1][n2][len] == true) return true;
        if(s1.substr(n1, len) == s2.substr(n2, len)) {
            dp[n1][n2][len] = true;
            return true;
        }

        vector<int> charset(26, 0);
        for(int i = n1; i < n1 + len; i++) {
            charset[s1[i] - 'a']++;
        }

        for(int i = n2; i < n2 + len; i++) {
            charset[s2[i] - 'a']--;
        }

        for(int i = 0; i < 26; i++) {
            if(charset[i] != 0) {
                dp[n1][n2][len] = false;
                return false;
            }
        }
        
        bool result;
        for(int i = 1; i < len; i++) {
            result = (isScrambleRecur(dp, s1, s2, n1, n2, i) == 1) && (isScrambleRecur(dp, s1, s2, n1 + i, n2 + i, len - i) == true);
            if(result) {
                dp[n1][n2][len] = true;
                return true;
            }
            result = (isScrambleRecur(dp, s1, s2, n1 + len - i, n2, i) == 1) && (isScrambleRecur(dp, s1, s2, n1, n2 + i, len - i) == true);
            if(result) {
                dp[n1][n2][len] = true;
                return true;
            }
        }

        dp[n1][n2][len] = false;
        return false;
    }

public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2) return true;
        if(s1.size() != s2.size()) return false;
        int n = s1.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n + 1, 0)));
        if(isScrambleRecur(dp, s1, s2, 0, 0, n) == true) {
            return true;
        } else {
            return false;
        }
    }
};
