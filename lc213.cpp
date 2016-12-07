class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        return max(rob_sub(nums, 0, nums.size() - 2), rob_sub(nums, 1, nums.size() - 1));
    }
    int rob_sub(vector<int>& nums,int left, int right) {
        if(left == right) return nums[left];
        vector<int> dp(2, 0);
        dp[0] = nums[left];
        dp[1] = max(nums[left], nums[left + 1]);
        int i = 2;
        while(left + i <= right){
            if(i % 2 == 0){
                dp[0] = max(dp[1], dp[0] + nums[left + i]);
            }
            else{
                dp[1] = max(dp[0], dp[1] + nums[left + i]);
            }
            i++;
        }
        if((right - left + 1) % 2 != 0) return dp[0];
        return dp[1];
    }
};
