class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        int res = 0;
        for(int i = 0; i < m; i++){
            dp[i][0] = matrix[i][0] - '0';
            res = max(res, dp[i][0]);
        }
        for(int j = 0; j < n; j++){
            dp[0][j] = matrix[0][j] - '0';
            res = max(res, dp[0][j]);
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == '1'){
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                    dp[i][j] = min(dp[i][j], dp[i - 1][j]);
                    dp[i][j] = min(dp[i][j], dp[i][j - 1]);
                    dp[i][j]++;
                    res = max(res, dp[i][j]);
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        return res * res;
    }
};
