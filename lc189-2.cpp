//另一种解法，rotate两次即可，可以用swap(). swap()只对两个相同type有效。
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n <= 1) return;
        k = k % n;
        if(k == 0) return;
        reverseVec(nums, 0, n - 1 - k);
        reverseVec(nums, n - k, n - 1);
        reverseVec(nums, 0, n - 1);
        
        
    }
    void reverseVec(vector<int>& nums, int a, int b){
        if(a == b) return;
        int mid = (b - a + 1) / 2;
        for(int i = 0; i < mid; i++){
            swap(nums[a + i], nums[b - i]);
        }
    }
};
