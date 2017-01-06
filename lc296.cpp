class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0){
            return 0;
        }
        vector<int> xcoor;
        vector<int> ycoor;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    xcoor.push_back(i);
                    ycoor.push_back(j);
                }
            }
        }
        sort(xcoor.begin(), xcoor.end());
        sort(ycoor.begin(), ycoor.end());
        int res = 0;
        int i = 0;
        int j = xcoor.size() - 1;
        while(i < j){
            res = res + xcoor[j] - xcoor[i] + ycoor[j] - ycoor[i];
            i++;
            j--;
        }
        return res;
    }
};
