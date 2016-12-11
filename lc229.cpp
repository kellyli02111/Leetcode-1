class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int m = 0;
        int n = 0;
        int cm = 0;
        int cn = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == m){
                cm++;
            }
            else if(nums[i] == n){
                cn++;
            }
            else if(cm == 0){
                m = nums[i];
                cm = 1;
            }
            else if(cn == 0){
                n = nums[i];
                cn = 1;
            }
            else{
                cm--;
                cn--;
            }
        }
        cm = 0;
        cn = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == m){
                cm++;
            }
            if(nums[i] == n){
                cn++;
            }
        }
        if(cm > nums.size() / 3){
            res.push_back(m);
        }
        if(cn > nums.size() / 3 && n != m){
            res.push_back(n);
        }
        return res;
    }
};
