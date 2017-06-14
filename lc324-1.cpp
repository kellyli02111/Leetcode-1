class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        int n = nums.size();
        int first = (n - 1) / 2;
        int second = n - 1;
        for(int i = 0; i < n; i++){
            if(i % 2 == 0){
                nums[i] = tmp[first];
                first--;
            }
            else{
                nums[i] = tmp[second];
                second--;
            }
        }
    }
};
