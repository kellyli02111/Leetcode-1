class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_map<int, int> hashmap;
        for(int i = 0; i < nums.size(); i++){
            hashmap[nums[i]] = i;
        }
        vector<int> visited(nums.size(), 0);
        int res = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            if(visited[i] == 1) continue;
            int len = 1;
            int index = nums[i] - 1;
            while(hashmap.find(index) != hashmap.end()){
                visited[hashmap[index]] = 1;
                len++;
                index--;
            }
            index = nums[i] + 1;
            while(hashmap.find(index) != hashmap.end()){
                visited[hashmap[index]] = 1;
                len++;
                index++;
            }
            if (len > res){
                res = len;
            }
        }
        return res;
    }
};
