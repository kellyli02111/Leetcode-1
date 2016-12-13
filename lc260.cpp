class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_result = 0;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            xor_result = xor_result ^ nums[i];
        }
        int firstDigit = 0;
        for(int i = 0; i < 32; i++){
            if((xor_result >> i) & 1 == 1){
                firstDigit = i;
                break;
            }
        }
        int xor_result2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] >> firstDigit & 1 == 1){
                xor_result2 = xor_result2 ^ nums[i];
            }
        }
        res.push_back(xor_result2);
        res.push_back(xor_result2 ^ xor_result);
        return res;
    }
};
