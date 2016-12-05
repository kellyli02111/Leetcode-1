class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        if(k >= prices.size()) return maxProfitSub(prices);
        vector<int> local(k + 1, 0);
        vector<int> global(k + 1, 0);
        for(int i = 0; i < prices.size() - 1; i++){
            int diff = prices[i + 1] - prices[i];
            for(int j = k; j >= 1; j--){
                //必须从k到1, 否则使用的不是上一轮循环的值
                local[j] = max(global[j - 1] + max(diff, 0), local[j] + diff);
                global[j] = max(local[j], global[j]);
            }
        }
        return global[k];
    }
    
    int maxProfitSub(vector<int>& prices){
        int profit = 0;
        for(int i = 1; i < prices.size(); i++){
            profit = profit + max(0, prices[i] - prices[i - 1]);
        }
        return profit;
    }
};
