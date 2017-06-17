class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int res = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                res = max(res, dfs(matrix, dp, visited, i, j));
            }
        }
        return 1 + res;
    }
    
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, vector<vector<bool>>& visited, int x, int y){
        if(visited[x][y]) return dp[x][y];
        vector<vector<int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;
        for(int i = 0; i < dirs.size(); i++){
            int nextX = x + dirs[i][0];
            int nextY = y + dirs[i][1];
            if(nextX < 0 || nextY < 0 || nextX >= m || nextY >= n || matrix[nextX][nextY] <= matrix[x][y]) continue;
            res = max(res, 1 + dfs(matrix, dp, visited, nextX, nextY));
        }
        visited[x][y] = true;
        dp[x][y] = res;
        return res;
    }
};
