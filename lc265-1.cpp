class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if(costs.empty() || costs[0].empty()) return 0;
        int n = costs.size();
        int k = costs[0].size();
        vector<int> dp(k, 0);
        for(int i = 0; i < k; i++){
            dp[i] = costs[0][i];
        }
        for(int i = 1; i < n; i++){
            int minInd1, minInd2;
            if(dp[0] <= dp[1]){
                minInd1 = 0;
                minInd2 = 1;
            }
            else{
                minInd1 = 1;
                minInd2 = 0;
            }
            for(int j = 2; j < k; j++){
                if(dp[j] < dp[minInd1]){
                    minInd2 = minInd1;
                    minInd1 = j;
                }
                else if(dp[j] >= dp[minInd1] && dp[j] < dp[minInd2]){
                    minInd2 = j;
                }
            }
            vector<int> newDp = dp;
            for(int j = 0; j < k; j++){
                if(j == minInd1){
                    newDp[j] = dp[minInd2] + costs[i][j];
                }
                else{
                    newDp[j] = dp[minInd1] + costs[i][j];
                }
            }
            dp = newDp;
        }
        int res = INT_MAX;
        for(int i = 0; i < k; i++){
            res = min(res, dp[i]);
        }
        return res;
    }
};
