class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        return findMin_sub(nums, 0, n - 1);
    }
    int findMin_sub(vector<int>& nums, int a, int b){
        if(a == b) return nums[a];
        int mid = a + (b - a) / 2;
        if(nums[mid] < nums[b]){
            return findMin_sub(nums, a, mid);
        }
        return findMin_sub(nums, mid + 1, b);
    }
};
