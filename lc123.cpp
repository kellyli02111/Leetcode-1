class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        vector<int> left(prices.size(), 0);
        vector<int> right(prices.size(), 0);
        int minPrice = prices[0];
        for(int i = 1; i < prices.size(); i++){
            left[i] = max(prices[i] - minPrice, left[i - 1]);
            minPrice = min(minPrice, prices[i]);
        }
        right[prices.size() - 1] = 0;
        int maxPrice = prices[prices.size() - 1];
        for(int i = prices.size() - 2; i >=0; i--){
            right[i] = max(right[i + 1], maxPrice - prices[i]);
            maxPrice = max(maxPrice, prices[i]);
        }
        int res = 0;
        for(int i = 0; i < prices.size(); i++){
            res = max(res, left[i] + right[i]);
        }
        return res;
    }
};
