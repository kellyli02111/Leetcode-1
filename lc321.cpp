class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res;
        int m = nums1.size();
        int n = nums2.size();
        for(int i = max(0, k - n); i <= min(m, k); i++){
            res = max(res, mergeVector(maxVector(nums1, i), maxVector(nums2, k - i)));//lexigraphically compare
        }
        return res;
    }
    
    vector<int> maxVector(vector<int> nums, int k){
        vector<int> res;
        int n = nums.size();
        int drop = n - k;
        for(int i = 0; i < n; i++){
            while(drop > 0 && res.size() > 0 && res.back() < nums[i]){
                res.pop_back();
                drop--;
            }
            res.push_back(nums[i]);
        }
        res.resize(k);
        return res;
    }
    
    vector<int> mergeVector(vector<int> nums1, vector<int> nums2){
        vector<int> res;
        while(nums1.size() > 0 || nums2.size() > 0){
            if(nums1 > nums2){//lexigraphically compare
                res.push_back(nums1[0]);
                nums1.erase(nums1.begin());
            }
            else{
                res.push_back(nums2[0]);
                nums2.erase(nums2.begin());
            }
        }
        return res;
    }
};
