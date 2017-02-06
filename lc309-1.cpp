//http://www.cnblogs.com/grandyang/p/4997417.html
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;
        vector<int> buy(n, 0);
        vector<int> sell(n, 0);
        vector<int> rest(n, 0);
        buy[0] = 0 - prices[0];
        for(int i = 1; i < n; i++){
            buy[i] = max(rest[i - 1] - prices[i], buy[i - 1]);
            rest[i] = max(sell[i - 1], rest[i - 1]);
            sell[i] = max(buy[i - 1] + prices[i], sell[i - 1]);
        }
        return sell[n - 1];
    }
};
