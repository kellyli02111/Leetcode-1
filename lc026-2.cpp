class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int writeIndex = 1;
        for(int i = 1; i < n; i++){
            if(nums[writeIndex - 1] != nums[i]){
                nums[writeIndex] = nums[i];
                writeIndex++;
            }
        }
        return writeIndex;
    }
};
