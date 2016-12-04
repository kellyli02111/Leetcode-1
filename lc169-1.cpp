class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cur = nums[0];
        int vote = 1;
        for(int i = 1; i < nums.size(); i++){
            if(vote == 0){
                vote = 1;
                cur = nums[i];
                continue;
            }
            
            if(nums[i] == cur) vote++;
            else vote--;
        }
        return cur;
    }
};
