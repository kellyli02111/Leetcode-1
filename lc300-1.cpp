//O(n^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        vector<int> v(n, 1);
        int res = 1;
        v[0] = 1;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i] && v[j] >= v[i]){
                    v[i] = v[j] + 1;
                }
            }
            res = max(res, v[i]);
        }
        return res;
    }
};
