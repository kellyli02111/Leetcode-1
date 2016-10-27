class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        if(prices.size() < 2) return 0;
        int curMin = prices[0];
        int curMax = prices[0];
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] < curMin){
                curMin = prices[i];
                curMax = prices[i];
            }
            if(prices[i] > curMax){
                curMax = prices[i];
                res = max(res, curMax - curMin);
            }
        }
        return res;
    }
};
