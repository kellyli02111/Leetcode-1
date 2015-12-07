class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> newGrid(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++){
            if(obstacleGrid[i][0] != 1){
                newGrid[i][0] = 1;
            } else {
                break;
            }
        }
        for (int i = 0; i < n; i++){
            if(obstacleGrid[0][i] != 1){
                newGrid[0][i] = 1;
            } else {
                break;
            }
        }

        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++){
                if(obstacleGrid[i][j] == 0){
                    newGrid[i][j] = newGrid[i - 1][j]+newGrid[i][j - 1];
                }
            }
        }
        return newGrid[m - 1][n - 1];
    }
};
