class NumArray {
    vector<int> numSum;
public:
    NumArray(vector<int> &nums) {
        if(!nums.empty()){
            numSum.push_back(nums[0]);
            for(int i = 1; i < nums.size(); i++){
                numSum.push_back(numSum[i - 1] + nums[i]);
            }
        }
    }

    int sumRange(int i, int j) {
        if(i == 0) return numSum[j];
        return (numSum[j] - numSum[i - 1]);
    }
};
