http://fisherlei.blogspot.com/2013/01/leetcode-search-in-rotated-sorted-array_3.html
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] == target) return true;
            if(nums[mid] > nums[l]){
                if(nums[l] <= target && target < nums[mid]){
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
            else if(nums[mid] < nums[l]){
                if(nums[mid] < target && target <= nums[r]){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
            else{
                l++;
            }
        }
        return false;
    }
};
