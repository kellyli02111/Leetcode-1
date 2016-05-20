class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.empty()) return res;
        vector<int> per(1, nums[0]);
        res.push_back(per);
        for(int i = 1; i < nums.size(); i++){
            int n = res.size();
            for(int j = 0; j < n; j++){
                for(int k = 0; k < res[j].size(); k++){
                    vector<int> per = res[j];
                    per.insert(per.begin() + k, nums[i]);
                    res.push_back(per);
                }
                res[j].push_back(nums[i]);
            }
        }
        return res;
    }
};
