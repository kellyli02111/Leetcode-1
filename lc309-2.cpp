//http://www.cnblogs.com/grandyang/p/4997417.html
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;
        int preBuy = -prices[0];
        int buy = -prices[0];
        int preSell = 0;
        int sell = 0;
        
        for(int i = 1; i < n; i++){
            preBuy = buy;
            buy = max(preBuy, preSell - prices[i]);
            preSell = sell;
            sell = max(preSell, preBuy + prices[i]);
        }
        return sell;
    }
};
