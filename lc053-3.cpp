//O(n): 先找以每个元素结尾的最大值，再比较所有的最大值
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int local = nums[0];
        int global = nums[0];
        for (int i = 1; i<n; i++){
            local = max(local+nums[i],nums[i]);
            global = max(local,global);
        }
        return global;
    }
};
