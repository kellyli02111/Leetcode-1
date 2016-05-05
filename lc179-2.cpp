class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if(nums.size() == 0) return "";
        string res = "";
        while(!nums.empty()){
            int index1 = 0;
            for(int index2 = index1; index2 < nums.size(); index2++){
                if((to_string(nums[index2]) + to_string(nums[index1])) > (to_string(nums[index1]) + to_string(nums[index2]))){
                    index1 = index2;
                }
            }
            res = res + to_string(nums[index1]);
            nums.erase(nums.begin() + index1);
        }
        while((res.size() > 1) && (res[0] == '0')){
            res.erase(res.begin());
        }
        return res;
    }
};
