//最优的桶的大小为可能有的maximum gap的最小值 - 1
//等于(maxVal - minVal - 1) / (n - 1) + 1 = ceil((maxVal - minVal) / (n - 1))
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        int maxVal = nums[0];
        int minVal = nums[0];
        for(int i = 1; i < n; i++){
            maxVal = max(maxVal, nums[i]);
            minVal = min(minVal, nums[i]);
        }
        int bSize = (maxVal - minVal - 1) / (n - 1) + 1;
        int count = (maxVal - minVal) / bSize + 1;//在能整除的情况下会多一个桶，但若不能整除就一定要有 + 1
        vector<int> bMax(count, -1);
        vector<int> bMin(count, -1);
        for(int i = 0; i < n; i++){
            int bIndex = (nums[i] - minVal) / bSize;
            if(bMax[bIndex] == -1){
                bMax[bIndex] = nums[i];
                bMin[bIndex] = nums[i];
            }
            else{
                bMax[bIndex] = max(bMax[bIndex], nums[i]);
                bMin[bIndex] = min(bMin[bIndex], nums[i]);
            }
        }
        int res = 0;
        int pre = 0;
        while(bMax[pre] == -1){
            pre++;
        }
        int cur = pre + 1;
        while(bMax[cur] == -1){
            cur++;
        }
        while(cur != count){
            res = max(res, bMin[cur] - bMax[pre]);
            pre = cur;
            cur++;
            while(cur < count && bMax[cur] == -1 ){
                cur++;
            }
        }
        return res;
    }
};
