class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int aInd = 0;
        int maxDiff = INT_MAX;
        int minDiff = INT_MIN;
        while(aInd < n - 2){
            int bInd = aInd + 1;
            int cInd = n - 1;
            while(bInd < cInd){
                int sum = nums[aInd] + nums[bInd] + nums[cInd];
                int diff = sum - target;
                if(diff == 0) return target;
                if(diff < 0){
                    if(diff > minDiff){
                        minDiff = diff;
                    }
                    while(nums[bInd] == nums[bInd + 1]){
                        bInd++;
                    }
                    bInd++;
                }
                if(diff > 0){
                    if(diff < maxDiff){
                        maxDiff = diff;
                    }
                    while(nums[cInd] == nums[cInd - 1]){
                        cInd--;
                    }
                    cInd--;
                }
            }
            while(nums[aInd] == nums[aInd + 1]){
                aInd++;
            }
            aInd++;
        }
        if(minDiff + maxDiff > 0){
            return target + minDiff;
        }
        else{
            return target + maxDiff;
        }
    }
};
