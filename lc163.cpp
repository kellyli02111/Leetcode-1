class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        int prev = lower - 1;
        int curr = 0;
        for(int i = 0; i <= nums.size(); i++){
            if(i == nums.size()){
                curr = upper + 1;
            }
            else{
                curr = nums[i];
            }
            if(curr > prev + 1){
                res.push_back(printRanges(prev + 1, curr - 1));
            }
            prev = curr;
        }
        return res;
    }
    
    string printRanges(int lower, int upper){
        if(lower == upper){
            return to_string(lower);
        }
        else{
            return to_string(lower) + "->" + to_string(upper);
        }
    }
};
