class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        vector<int> dp(2, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        int i = 2;
        while(i < nums.size()){
            if(i % 2 == 0){
                dp[0] = max(dp[1], dp[0] + nums[i]);
            }
            else{
                dp[1] = max(dp[0], dp[1] + nums[i]);
            }
            i++;
        }
        if(nums.size() % 2 != 0) return dp[0];
        return dp[1];
    }
};
