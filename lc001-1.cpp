class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int i,j;
        for (i=0;i<=nums.size()-2;i++){
            for (j=i+1;j<=nums.size()-1;j++){
                if(nums[i]+nums[j]==target){
                    res.push_back(i+1);
                    res.push_back(j+1);
                    break;
                }
            }
        }
        return res;
    }
};
//res.push_back是从后面push进来
