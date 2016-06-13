class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> solution;
        vector<vector<int>> res;
        getSubsets(0, nums, solution, res);
        return res;
    }
    
    void getSubsets(int lvl, vector<int>& nums, vector<int>& solution, vector<vector<int>>& res){
        res.push_back(solution);
        for(int i = lvl; i < nums.size(); i++){
            solution.push_back(nums[i]);
            getSubsets(i + 1, nums, solution, res);
            solution.pop_back();
            while(i < (nums.size() - 1) && nums[i + 1] == nums[i]){
                i++;
            }
        }
    }
};
