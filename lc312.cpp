//http://www.cnblogs.com/grandyang/p/5006441.html
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() == 0) return 0;
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for(int len = 1; len <= n; len++){
            for(int left = 1; left <= n + 1 - len; left++){
                int right = left + len - 1;
                for(int k = left; k <= right; k++){
                    dp[left][right] = max(dp[left][right], dp[left][k - 1] + dp[k + 1][right] + nums[left - 1] * nums[k] * nums[right + 1]);
                }
            }
        }
        return dp[1][n];
    }
};
