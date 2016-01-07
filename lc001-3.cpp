class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> res;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(m[target - nums[i]] != 0){
                res.push_back(m[target - nums[i]]);
                res.push_back(i + 1);
                return res;
            }
            else{
                m[nums[i]] = i + 1;
            }
        }
    }
};
