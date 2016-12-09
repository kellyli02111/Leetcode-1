class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> res;
        vector<pair<int, int>> height;
        multiset<int> ms;
        for(int i = 0; i < buildings.size(); i++){
            height.push_back({buildings[i][0], -buildings[i][2]});
            height.push_back({buildings[i][1], buildings[i][2]});
        }
        sort(height.begin(), height.end());
        ms.insert(0);
        int pre = 0;
        int cur = 0;
        for(int i = 0; i < height.size(); i++){
            if(height[i].second < 0){
                ms.insert(-height[i].second);
            }
            else{
                ms.erase(ms.find(height[i].second));
            }
            cur = *ms.rbegin();
            if(cur != pre){
                res.push_back({height[i].first, cur});
                pre = cur;
            }
        }
        return res;
    }
};
