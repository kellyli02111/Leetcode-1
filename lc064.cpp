class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> resGrid(m,vector<int>(n,grid[0][0]));
        for(int i = 1; i<n; i++){
            resGrid[0][i] = resGrid[0][i-1]+grid[0][i];
        }
        for(int i = 1; i<m; i++){
            resGrid[i][0] = resGrid[i-1][0]+grid[i][0];
            for(int j = 1; j<n; j++){
                resGrid[i][j] = min(resGrid[i-1][j],resGrid[i][j-1])+grid[i][j];
            }
        }
        return resGrid[m-1][n-1];
    }
};
