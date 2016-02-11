class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndex = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(maxIndex < i) return false;
            maxIndex = max(maxIndex, i + nums[i]);
        }
        if(maxIndex >= nums.size() - 1) return true;
        return false;
    }
};
