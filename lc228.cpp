class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.empty()) return res;
        int begin = 0;
        int end = 0;
        while(end < nums.size() - 1){
            if(nums[end + 1] - nums[end] == 1){
                end++;
            }
            else{
                if(end != begin){
                    res.push_back(to_string(nums[begin]) + "->" + to_string(nums[end]));
                    begin = end + 1;
                    end = begin;
                }
                else{
                    res.push_back(to_string(nums[begin]));
                    begin++;
                    end++;
                }
            }
        }
        if(end != begin){
            res.push_back(to_string(nums[begin]) + "->" + to_string(nums[end]));
        }
        else{
            res.push_back(to_string(nums[begin]));
        }
        return res;
    }
};
