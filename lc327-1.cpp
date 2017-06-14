//http://www.cnblogs.com/grandyang/p/5162678.html
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int res = 0;
        long long sum = 0;
        multiset<long long> sums;
        int n = nums.size();
        sums.insert(0); //必须有
        for(int i = 0; i < n; i++){
            sum = sum + nums[i];
            res = res + distance(sums.lower_bound(sum - upper), sums.upper_bound(sum - lower));
            sums.insert(sum);
        }
        return res;
    }
};
