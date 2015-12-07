class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        vector<int> numsNew;
        for(int i = 0; i<=n-1; i++){
            if(nums[i] == 0){
                numsNew.push_back(0);
            }
        }
        for(int i = 0; i<=n-1; i++){
            if(nums[i] == 1){
                numsNew.push_back(1);
            }
        }
        for(int i = 0; i<=n-1; i++){
            if(nums[i] == 2){
                numsNew.push_back(2);
            }
        }
        for(int i = 0; i<=n-1; i++){
            nums[i] = numsNew[i];
        }
    }
};
