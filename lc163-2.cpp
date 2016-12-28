class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        long long low = lower;
        long long up = upper;
        long long prev = low - 1;
        long long curr = 0;
        for(int i = 0; i <= nums.size(); i++){
            if(i == nums.size()){
                curr = up + 1;
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
    
    string printRanges(long long low, long long up){
        if(low == up){
            return to_string(low);
        }
        else{
            return to_string(low) + "->" + to_string(up);
        }
    }
};
