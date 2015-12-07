//任何两个相同的数异或都等于0，任何数和0异或都等于其本身
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            res = res ^ nums[i];
        }
        return res;
    }
};
