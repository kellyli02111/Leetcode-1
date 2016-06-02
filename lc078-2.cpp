class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> record;
        vector<vector<int>> res;
        int n = nums.size();
        unsigned long long bitmax = (1 << n);
        for(unsigned long long i = 0; i < bitmax; i++){
            record.clear();
            for(int j = 0; j < n; j++){
                if((i >> j) & 1 == 1){
                    record.push_back(nums[j]);
                }
            }
            res.push_back(record);
        }
        return res;
    }
};
