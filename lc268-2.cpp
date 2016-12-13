class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xorRes = 0;
        for(int i = 0; i < n; i++){
            xorRes = xorRes ^ i;
            xorRes = xorRes ^ nums[i];
        }
        xorRes = xorRes ^ n;
        return xorRes;
    }
};
