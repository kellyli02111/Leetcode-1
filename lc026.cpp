class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        vector<int> numsNew;
        if(n <= 1){
            return n;
        }
        else{
            for(int i = 0; i<=n-2; i++){
                if(nums[i] != nums[i+1]){
                    numsNew.push_back(nums[i]);
                    res = res + 1;
                }
            }
            numsNew.push_back(nums[n-1]);
            res = res + 1;
            n = numsNew.size();
            for (int i = 0; i<=n-1; i++){
                nums[i] = numsNew[i];
            }
            return res;
        }
    }
};
