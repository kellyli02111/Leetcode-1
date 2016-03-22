class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp;
        vector<string> temp;
        temp.push_back("");
        dp.push_back(temp);
        for(int i = 1; i <= n; i++){
            temp.clear();
            for(int j = 0; j < i; j++){
                int k = i - 1 - j;
                for(int jj = 0; jj < dp[j].size(); jj++){
                    for(int kk = 0; kk < dp[k].size(); kk++){
                        temp.push_back("(" + dp[j][jj] + ")" + dp[k][kk]);
                    }
                }
            }
            dp.push_back(temp);
        }
        return dp[n];
    }
};
