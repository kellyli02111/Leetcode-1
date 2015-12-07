class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n <= 1) return;
        k = k % n;
        int start = 0;
        int curStart = start;
        int count = 0;
        int tar = (curStart + k) % n;
        int temp = nums[start];
        while(count == 0 || curStart != start){
            int temp2 = nums[tar];
            nums[tar] = temp;
            temp = temp2;
            curStart  = tar;
            tar = (curStart + k) % n;
            count++;
        }
        if(n / count > 1){
            for(int i = 0; i < n / count - 1; i++){
                start++;
                int curStart = start;
                int count = 0;
                int tar = (curStart + k) % n;
                int temp = nums[start];
                while(count == 0 || curStart != start){
                    int temp2 = nums[tar];
                    nums[tar] = temp;
                    temp = temp2;
                    curStart  = tar;
                    tar = (curStart + k) % n;
                    count++;
                }
            }
        }
    }
};
