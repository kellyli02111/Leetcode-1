class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int start = 0;
        int end = nums.size() - 1;
        if((nums[start] > target) || (nums[end] < target)){
            res = {-1, -1};
            return res;
        }
        bool found = false;
        if(nums[end] == target){
            found = true;
        }
        if(nums[0] == target){
            found = true;
            res.push_back(0);
        }
        else{
            while(start < end){
                int mid = (start + end) / 2;
                if(nums[mid] == target){
                    found = true;
                    end = mid;
                }
                else if(nums[mid] > target){
                    end = mid;
                }
                else{
                    start = mid + 1;
                }
            }
            if(found == false){
                res = {-1, -1};
                return res;
            }
            res.push_back(end);
        }
        
        start = 0;
        end = nums.size() - 1;
        if(nums[end] == target){
            res.push_back(end);
        }
        else{
            while(start < end){
                int mid = (start + end) / 2;
                if(nums[mid] == target){
                    start = mid + 1;
                }
                else if(nums[mid] > target){
                    end = mid;
                }
                else{
                    start = mid + 1;
                }
            }
            res.push_back(end - 1);
        }
        return res;
    }
};
