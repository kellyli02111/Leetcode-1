//O(n^2):
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp(3,0);
        int n = nums.size();
        sort(nums.begin(),nums.end());
        //printVector(nums);
        if(n < 3) return res;
        int aInd = 0;
        while((nums[aInd] <= 0) && (aInd < n - 2)){
            int bInd = aInd + 1;
            int cInd = n-1;
            while((bInd < cInd) && (nums[cInd] >= 0)){
                int sum = nums[aInd] + nums[bInd] + nums[cInd];
                if(sum == 0){
                    temp[0] = nums[aInd];
                    temp[1] = nums[bInd];
                    temp[2] = nums[cInd];
                    res.push_back(temp);
                    while(nums[bInd] == nums[bInd + 1]){
                        bInd++;
                    }
                    bInd++;
                }
                if(sum < 0){
                    while(nums[bInd] == nums[bInd + 1]){
                        bInd++;
                    }
                    bInd++;
                }
                if(sum > 0){
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
        return res;
    }
};
//Leetcode里的main是隐藏的，用来run现在的函数和test case，如果括号错误就会影响到main的执行。
