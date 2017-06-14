//http://www.cnblogs.com/grandyang/p/5336668.html
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0) return 0;
        int res = 0;
        unordered_map<int, vector<int>> um;
        int sum = nums[0];
        um[sum].push_back(0);
        for(int i = 1; i < n; i++){
            sum = sum + nums[i];
            um[sum].push_back(i);
        }
        for(auto it = um.begin(); it != um.end(); it++){
            if(it->first == k){
                res = max(res, it->second.back() + 1);
            }
            else{
                if(um.find(it->first - k) != um.end()){
                    res = max(res, (it->second).back() - um[it->first - k][0]);
                }
            }
        }
        return res;
    }
};
