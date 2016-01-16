class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        int n = s.size();
        if(n <= 1) return 0;
        vector<int> maxLen(n, 0);
        maxLen[n - 1] = 0;
        for(int i = n - 2; i >=0; i--){
            if(s[i] == ')'){
                maxLen[i] = 0;
            }
            else{
                int j = i + 1 + maxLen[i + 1];
                if(j < n && s[j] == ')'){
                    maxLen[i] = maxLen[i + 1] + 2;
                    if(j + 1 < n){
                        maxLen[i] = maxLen[i] + maxLen[j + 1];
                    }
                }
            }
            res = max(res, maxLen[i]);
        }
        return res;
    }
};
