class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        int res = n + 1;
        vector<int> sums(n + 1, 0);
        for(int i = 1; i <= n; i++){
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        for(int i = 0; i < n; i++){
            int right = searchRight(i + 1, n, sums[i] + s, sums);
            if(right == n + 1) break;
            if(res > right - i){
                res = right - i;
            }
        }
        if(res == n + 1) return 0;
        return res;
    }
    
    int searchRight(int left, int right, int key, vector<int>& sums){
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(sums[mid] >= key){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};
