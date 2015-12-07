//O(n^2)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            int base = nums[i];
            if (base > res){
                res = base;
            }
            for (int j = i+1; j < n; j++){
                base = base + nums[j];
                if (base > res){
                    res = base;
                }
            }
        }
        return res;
    }
};
