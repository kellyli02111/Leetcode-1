class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return 0;
        int end = n - 1;
        int start = end;
        int step = 0;
        while(end > 0){
            int cur = end;
            int start = end;
            while(cur >= 0){
                if(cur + nums[cur] >= end && cur < start){
                    start = cur;
                }
                cur--;
            }
            step++;
            end = start;
        }
        return step;
    }
};
