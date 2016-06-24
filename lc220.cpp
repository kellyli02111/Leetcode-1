class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(k < 1 || t < 0) return false;
        unordered_map<int, long long> um;
        queue<int> keys;
        for(int i = 0; i < nums.size(); i++){
            int key = nums[i] / max(t, 1);
            for(int j = key - 1; j <= key + 1; j++){
                if(um.find(j) != um.end() && abs(um[j] - nums[i]) <= (long long)t){
                    return true;
                }
            }
            um[key] = nums[i];
            keys.push(key);
            if(um.size() > k){
                um.erase(keys.front());
                keys.pop();
            }
        }
        return false;
    }
};
