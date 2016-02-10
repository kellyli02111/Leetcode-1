class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return 0;
        int start = 0;
        int end = n - 1;
        while(start <= end){
            if(start == end) return start;
            int mid = start + (end - start) / 2;
            if(nums[mid] > nums[mid + 1]){
                end = mid;
            }
            else{
                start = mid + 1;
            }
        }
    }
};
