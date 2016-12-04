class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < 32; i++){
            int count = 0;
            for(int j = 0; j < nums.size(); j++){
                if((nums[j] >> i) & 1) count++;
            }
            if(count > nums.size() / 2){
                res = res | (1 << i);
            }
        }
        return res;
    }
};
