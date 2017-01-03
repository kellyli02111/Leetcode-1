//Time: O(nlogn);
//Space: O(1);
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int min = 1;
        int max = nums.size() - 1;
        while(min < max){
            cout<<min<<"##"<<max<<endl;
            int count = 0;
            int mid = min + (max - min) / 2;
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] >= min && nums[i] <= mid){
                    count++;
                }
            }
            if(count > (mid - min + 1)){
                max = mid;
            }
            else{
                min = mid + 1;
            }
        }
        return min;
    }
};
