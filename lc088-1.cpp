class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = m; i >=1; i--){
            nums1[n - 1 + i] = nums1[i - 1];
        }
        int index1 = 0;
        int index2 = n;
        int index3 = 0;
        while(index2 <= n + m - 1 && index3 <= n - 1){
            if(nums1[index2] <= nums2[index3]){
                nums1[index1] = nums1[index2];
                index1++;
                index2++;
            }
            else{
                nums1[index1] = nums2[index3];
                index1++;
                index3++;
            }
        }
        while(index3 <= n - 1){
            nums1[index1] = nums2[index3];
            index1++;
            index3++;
        }
    }
};
