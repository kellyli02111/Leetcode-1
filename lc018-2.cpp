class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> temp(4, 0);
        int n = nums.size();
        if(n < 4) return res;
        sort(nums.begin(), nums.end());
        unordered_map<int, vector<pair<int, int>>> twoSumMap;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                twoSumMap[nums[i] + nums[j]].push_back(make_pair(i, j));
            }
        }
        int aInd = 0;
        while(aInd < n - 3){
            int bInd = aInd + 1;
            while(bInd < n - 2){
                int targetTwo = target - nums[aInd] - nums[bInd];
                if(twoSumMap.find(targetTwo) != twoSumMap.end()){
                    vector<pair<int, int>> twoSumPair = twoSumMap[targetTwo];
                    int nTwoSum = twoSumPair.size();
                    bool first = true;
                    for(int ind = 0; ind < nTwoSum; ind++){
                        if(twoSumPair[ind].first <= bInd) continue;
                        if(first || (res.back()[2] != nums[twoSumPair[ind].first])){
                            temp[0] = nums[aInd];
                            temp[1] = nums[bInd];
                            temp[2] = nums[twoSumPair[ind].first];
                            temp[3] = nums[twoSumPair[ind].second];
                            res.push_back(temp);
                            first = false;
                        }
                    }
                }
                while(nums[bInd] == nums[bInd + 1]){
                    bInd++;
                }
                bInd++;
            }
            while(nums[aInd] == nums[aInd + 1]){
                aInd++;
            }
            aInd++;
        }
        return res;
    }
};
