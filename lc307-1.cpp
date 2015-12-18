//update: T: O(sqrt(n))
//sumRange: T: O(sqrt(n))
class NumArray {
    vector<int> numSum;
    vector<int> numArray;
    int groupSize;
public:
    NumArray(vector<int> &nums) {
        numArray = nums;
        int n = nums.size();
        groupSize = sqrt(n);
        if(!nums.empty()){
            for(int i = 0; i < n; i++){
                if(i % groupSize == 0){
                    numSum.push_back(nums[i]);
                }
                else{
                    numSum.push_back(numSum[i - 1] + nums[i]);
                }
            }
        }
    }

    void update(int i, int val) {
        int diff = val - numArray[i];
        int n = numSum.size();
        numArray[i] = val;
        for(int j = i; j < min(n, (i / groupSize + 1) * groupSize); j++){
            numSum[j] = numSum[j] + diff;
        }
    }

    int sumRange(int i, int j) {
        int res = 0;
        int groupi = i / groupSize;
        int groupj = j / groupSize;
        if(groupi == groupj){
            if(i % groupSize == 0) return numSum[j];
            else{
                return numSum[j] - numSum[i - 1];
            }
        }
        else{
            for(int k = groupi + 1; k < groupj; k++){
                res = res + numSum[(k + 1) * groupSize - 1];
            }
            if(i % groupSize == 0){
                res = res + numSum[(groupi + 1) * groupSize - 1];
            }
            else{
                res = res + (numSum[(groupi + 1) * groupSize - 1] - numSum[i - 1]);
            }
            res = res + numSum[j];
        }
        return res;
    }
};
