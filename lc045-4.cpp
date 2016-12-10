class Solution {
public:
    int jump(vector<int>& nums) {
        int lastMax = 0;
        int curMax = 0;
        int nStep = 0;
        int i = 0;
        while(lastMax < nums.size() - 1){
            for(; i <= lastMax; i++){
                curMax = max(curMax, i + nums[i]);
            }
            nStep++;
            lastMax = curMax;
        }
        return nStep;
    }
};
