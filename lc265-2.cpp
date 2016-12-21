class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if(costs.empty() || costs[0].empty()) return 0;
        int n = costs.size();
        int k = costs[0].size();
        int min1 = 0;
        int min2 = 0;
        int idx1 = -1;
        for(int i = 0; i < n; i++){
            int m1 = INT_MAX;
            int m2 = INT_MAX;
            int id1 = -1;
            for(int j = 0; j < k; j++){
                int cost;
                if(j == idx1){
                    cost = min2 + costs[i][j];
                }
                else{
                    cost = min1 + costs[i][j];
                }
                if(cost < m1){
                    m2 = m1;
                    m1 = cost;
                    id1 = j;
                }
                else if(cost < m2){
                    m2 = cost;
                }
            }
            min1 = m1;
            min2 = m2;
            idx1 = id1;
        }
        
        
        return min1;
    }
};
