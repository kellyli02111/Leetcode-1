class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int res = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                res = max(res, dfs(matrix, dp, i, j));
            }
        }
        return 1 + res;
    }
    
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int x, int y){
        if(dp[x][y] > 0) return dp[x][y];
        vector<vector<int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;
        for(int i = 0; i < dirs.size(); i++){
            int nextX = x + dirs[i][0];
            int nextY = y + dirs[i][1];
            if(nextX < 0 || nextY < 0 || nextX >= m || nextY >= n || matrix[nextX][nextY] <= matrix[x][y]) continue;
            res = max(res, 1 + dfs(matrix, dp, nextX, nextY));
        }
        dp[x][y] = res;
        return res;
    }
};
