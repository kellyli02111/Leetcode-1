class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> sums(n + 1, 0);
        for(int i = 0; i < n; i++){
            sums[i + 1] = sums[i] + nums[i];
        }
        return mergeSort(sums, 0, n + 1, lower, upper);
    }
    
    int mergeSort(vector<long long>& sums, int start, int end, int lower, int upper){
        if(end - start <= 1) return 0;
        int mid = start + (end - start) / 2;
        int count = mergeSort(sums, start, mid, lower, upper) + mergeSort(sums, mid, end, lower, upper);
        int j = mid;
        int k = mid;
        int l = mid;
        vector<long long> temp(end - start, 0);
        for(int i = start, r = 0; i < mid; i++, r++){
            while(j < end && sums[j] - sums[i] <= upper) j++;
            while(k < end && sums[k] - sums[i] < lower) k++;
            while(l < end && sums[l] < sums[i]){
                temp[r] = sums[l];
                r++;
                l++;
            }
            temp[r] = sums[i];
            count = count + j - k;
        }
        copy(temp.begin(), temp.begin() + l - start, sums.begin() + start);
        return count;
    }
};
