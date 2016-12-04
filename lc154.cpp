class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        while(start < end){
            int mid = start + (end - start) / 2;
            if(nums[start] <= nums[mid] && nums[mid] < nums[end]) return nums[start];
            if(nums[mid] < nums[start] && nums[mid] < nums[end]){
                end = mid;
                continue;
            }
            if(nums[mid] > nums[start] && nums[mid] > nums[end]){
                start = mid + 1;
                continue;
            }
            if(nums[mid] == nums[start]){
                start++;
                continue;
            }
            if(nums[mid] == nums[end]){
                end--;
                continue;
            }
        }
        return nums[start];
    }
};
