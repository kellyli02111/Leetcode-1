class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return;
        int startInd = n - 2;
        while(startInd >= 0){
            if(nums[startInd] < nums[startInd + 1]){
                break;
            }
            startInd--;
        }
        if(startInd < 0){
            reverse(nums.begin(), nums.end());
        }
        else{
            cout<<startInd<<endl;
            bool firstSwap = true;
            int swapInd;
            for(int i = startInd + 1; i < n; i++){
                if(nums[i] > nums[startInd]){
                    if(firstSwap){
                        swapInd = i;
                        firstSwap = false;
                    }
                    else{
                        if(nums[i] < nums[swapInd]){
                            swapInd = i;
                        }
                    }
                }
            }
            swap(nums[startInd], nums[swapInd]);
            sort(nums.begin() + startInd + 1, nums.end());
        }
    }
};
