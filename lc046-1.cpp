class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> per;
        vector<bool> used(nums.size(), false);
        findPermute(nums, used, per, res);
        return res;
    }
    
    void findPermute(vector<int>& nums, vector<bool>& used, vector<int>& per, vector<vector<int>>& res){
        if(per.size() == nums.size()){
            res.push_back(per);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(used[i] == false){
                used[i] = true;
                per.push_back(nums[i]);
                findPermute(nums, used, per, res);
                per.pop_back();
                used[i] = false;
            }
        }
    }
};
