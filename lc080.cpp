class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        cout<<"n = "<<n<<endl;
        if(n <= 2){
            return n;
        }
        else{
            vector<int> numsNew;
            int res = 1;
            int counter = 1;
            numsNew.push_back(nums[0]);
            for (int i = 1; i < n; i++){
                if(nums[i] == nums[i-1]){
                    counter++;
                }
                else{
                    counter = 1;
                }
                if(counter<3){
                    numsNew.push_back(nums[i]);
                    res++;
                }
            }
            n = numsNew.size();
            for (int i = 0; i  <n; i++){
                nums[i] = numsNew[i];
            }
            return res;
        }
    }
};
