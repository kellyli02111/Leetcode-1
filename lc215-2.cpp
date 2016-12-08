class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, k - 1, 0, nums.size() - 1);
    }
    
    int quickSelect(vector<int>& nums, int k, int start, int end){
        int pivot = nums[(start + end) / 2];
        int left = start;
        int right = end;
        while(left <= right){
            while(nums[left] > pivot) left++;
            while(nums[right] < pivot) right--;
            if(left <= right){
                swap(nums, left, right);
                left++;
                right--;
            }
        }
        if(right >= k && right >= start){
            return quickSelect(nums, k, start, right);
        }
        if(left <= k  && left <= end){
            return quickSelect(nums, k, left, end);
        }
        return nums[k];
    }
    void swap(vector<int>& nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};
