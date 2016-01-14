class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> temp(4, 0);
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(n < 4) return res;
        int aInd = 0;
        while(aInd < n - 3){
            int bInd = aInd + 1;
            while(bInd < n - 2){
                int cInd = bInd + 1;
                int dInd = n - 1;
                while((cInd < dInd) && (nums[dInd] >= target/4)){
                    int sum = nums[aInd] + nums[bInd] + nums[cInd] + nums[dInd];
                    if(sum == target){
                        temp[0] = nums[aInd];
                        temp[1] = nums[bInd];
                        temp[2] = nums[cInd];
                        temp[3] = nums[dInd];
                        res.push_back(temp);
                        while(nums[cInd] == nums[cInd + 1]){
                            cInd++;
                        }
                        cInd++;
                    }
                    if(sum < target){
                        while(nums[cInd] == nums[cInd + 1]){
                            cInd++;
                        }
                        cInd++;
                    }
                    if(sum > target){
                        while(nums[dInd] == nums[dInd - 1]){
                            dInd--;
                        }
                        dInd--;
                    }
                }
                while(nums[bInd] == nums[bInd + 1]){
                    bInd++;
                }
                bInd++;
            }
            while(nums[aInd] == nums[aInd + 1]){
                aInd++;
            }
            aInd++;
        }
        return res;
    }
};
