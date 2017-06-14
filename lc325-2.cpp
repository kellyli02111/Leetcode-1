//http://www.cnblogs.com/grandyang/p/5336668.html
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0) return 0;
        int res = 0;
        unordered_map<int, int> um;
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum = sum + nums[i];
            if(sum == k){
                res = max(res, i + 1);
            }
            else if(um.find(sum - k) != um.end()){
                res = max(res, (i - um[sum - k]));
            }
            if(um.find(sum) == um.end()){
                um[sum] = i;
            }
        }
        return res;
    }
};
