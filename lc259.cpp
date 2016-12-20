class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int i = 0; i < n; i++){
            int j = i + 1;
            int k = n - 1;
            while(j < k){
                if(nums[i] + nums[j] + nums[k] >= target){
                    k--;
                }
                else{
                    res = res + k - j;
                    j++;
                }
            }
        }
        return res;
    }
};
