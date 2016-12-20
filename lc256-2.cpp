class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        if(n == 0) return 0;
        int dp0 = costs[0][0];
        int dp1 = costs[0][1];
        int dp2 = costs[0][2];
        for(int i = 1; i < costs.size(); i++){
            int newDp0 = min(dp1, dp2) + costs[i][0];
            int newDp1 = min(dp0, dp2) + costs[i][1];
            int newDp2 = min(dp0, dp1) + costs[i][2];
            dp0 = newDp0;
            dp1 = newDp1;
            dp2 = newDp2;
        }
        return min(min(dp0, dp1), dp2);
    }
};
