class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_set<int> s;
        for(int i = 0; i < nums.size(); i++){
            s.insert(nums[i]);
        }
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            if(s.find(nums[i]) == s.end()) continue;
            int upper = nums[i];
            int lower = nums[i];
            while(s.find(upper + 1) != s.end()){
                upper++;
                s.erase(upper);
            }
            while(s.find(lower - 1) != s.end()){
                lower--;
                s.erase(lower);
            }
            res = max(res, upper - lower + 1);
        }
        return res;
    }
};
