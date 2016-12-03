class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        int localMax = nums[0];
        int localMin = nums[0];
        int globalMax = nums[0];
        for(int i = 1; i < nums.size(); i++){
            int temp = localMax;
            localMax = max(max(localMax * nums[i], localMin * nums[i]), nums[i]);
            localMin = min(min(temp * nums[i], localMin * nums[i]), nums[i]);
            globalMax = max(globalMax, localMax);
        }
        return globalMax;
    }
};
