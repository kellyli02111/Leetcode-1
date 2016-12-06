class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty()) return 0;
        int start = 0;
        int end = 0;
        int curSum = nums[0];
        int minLen = INT_MAX;
        while(end < nums.size()){
            if(curSum >= s){
                minLen = min(minLen, end - start + 1);
                if(minLen == 1) return 1;
                curSum = curSum - nums[start];
                start++;
            }
            else{
                end++;
                if(end < nums.size()){
                    curSum = curSum + nums[end];
                }
            }
        }
        if(minLen == INT_MAX) return 0;
        return minLen;
    }
};
