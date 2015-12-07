//O(n^3)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int n = nums.size();
        for (int i = 1; i <= n; i++){
            for (int j = 0; j < n+1-i; j++){
                int sum = subArraySum(nums, j, i);
                if (sum > res){
                    res = sum;
                }
            }
        }
        return res;
    }
    
    int subArraySum(vector<int>& nums, int start, int length) {
        int res = 0;
        for (int i = start; i < start+length; i++){
            res = res + nums[i];
        }
        return res;
    }
};

//INT_MIN/INT_MAX 代表int类型的最小最大值
