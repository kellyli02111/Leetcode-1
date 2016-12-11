class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        if(n == 1) return res;
        //products before res[i];
        for(int i = 1; i < nums.size(); i++){
            res[i] = res[i - 1] * nums[i - 1];
        }
        int product = 1;
        //products after res[i] * products before res[i];
        for(int i = nums.size() - 2; i >= 0; i--){
            product = product * nums[i + 1];
            res[i] = res[i] * product;
        }
        return res;
    }
};
