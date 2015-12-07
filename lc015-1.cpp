//n^3:
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp(3,0);
        int n = nums.size();
        sort(nums.begin(),nums.end());
        printVector(nums);
        if(n < 3) return res;
        vector<int> iVec;
        for (int i = 0; i < n-2; i++){
            if(numExist(nums[i], iVec)) continue;
            vector<int> jVec;
            for(int j = i + 1; j < n-1; j++){
                if(numExist(nums[j], jVec)) continue;
                vector<int> kVec;
                for(int k = j + 1; k < n; k++){
                    if(numExist(nums[k], kVec)) continue;
                    if(nums[i] + nums[j] + nums[k] == 0){
                        iVec.push_back(nums[i]);
                        jVec.push_back(nums[j]);
                        kVec.push_back(nums[k]);
                        temp[0] = nums[i];
                        temp[1] = nums[j];
                        temp[2] = nums[k];
                        res.push_back(temp);
                    }
                }
            }
        }
        return res;
    }
    bool numExist(int num, vector<int> data){
        bool res = false;
        int n = data.size();
        for(int i = 0; i < n; i++){
            if(num == data[i]){
                res = true;
                break;
            }
        }
        return res;
    }
    void printVector(vector<int> nums) {
    	int n = nums.size();
    	for (int i = 0; i<n; i++) {
    		cout << nums[i] << " ";
    	}
    	cout << endl;
    }
};
