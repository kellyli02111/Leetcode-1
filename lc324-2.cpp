//https://discuss.leetcode.com/topic/32929/o-n-o-1-after-median-virtual-indexing/2
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        #define A(i) nums[(1 + 2 * i) % (n | 1)]
        int n = nums.size();
        auto midptr = nums.begin() + n / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
        int i = 0;
        int j = 0;
        int k = n - 1;
        while(j <= k){
            if(A(j) > mid){
                swap(A(i), A(j));
                i++;
                j++;
            }
            else if(A(j) < mid){
                swap(A(j), A(k));
                k--;
            }
            else{
                j++;
            }
        }
    }
};
