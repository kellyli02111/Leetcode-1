class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};
        int low = getLowerBound(nums, target);
        int high = getUpperBound(nums, target);
        if(low <= high){
            res[0] = low;
            res[1] = high;
        }
        return res;
    }
    
    int getLowerBound(vector<int>& nums, int target){
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(nums[mid] < target){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return l;
    }
    
    int getUpperBound(vector<int>& nums, int target){
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(nums[mid] > target){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return r;
    }
};
