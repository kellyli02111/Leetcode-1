class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        multimap<int, int> indexMap;
        int n = nums.size();
        vector<int> res;
        for(int i = 1; i <= n; i++){
            indexMap.insert(pair<int, int> (nums[i - 1], i));
        }
        multimap<int, int>::iterator iter1 = indexMap.begin();
        multimap<int, int>::iterator iter2 = indexMap.end();
        iter2--;
        while(iter1 != iter2){
            if(iter1->first + iter2->first == target){
                if(iter1->second < iter2->second){
                    res.push_back(iter1->second);
                    res.push_back(iter2->second);
                }
                else{
                    res.push_back(iter2->second);
                    res.push_back(iter1->second);
                }
                return res;
            }
            if(iter1->first + iter2->first < target){
                iter1++;
            }
            if(iter1->first + iter2->first > target){
                iter2--;
            }
        }
    }
};
