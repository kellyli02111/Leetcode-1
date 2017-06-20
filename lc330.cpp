//http://www.cnblogs.com/grandyang/p/5165821.html
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long miss = 1;
        int i = 0;
        int res = 0;
        int nSize = nums.size();
        while(miss <= n){
            if(i < nSize && miss >= nums[i]){
                miss = miss + nums[i];
                i++;
            }
            else{
                miss = miss + miss;
                res++;
            }
        }
        return res;
    }
};
