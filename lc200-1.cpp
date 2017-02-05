class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                dfs(grid, i, j, count);
            }
        }
        return count;
    }
    void dfs(vector<vector<char>>& grid, int x, int y, int& count){
        if(grid[x][y] == '0') return;
        count++;
        dfs_sub(grid, x, y);
    }
    
    void dfs_sub(vector<vector<char>>& grid, int x, int y){
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) return;
        if(grid[x][y] == '0') return;
        grid[x][y] = '0';
        dfs_sub(grid, x - 1, y);
        dfs_sub(grid, x + 1, y);
        dfs_sub(grid, x, y - 1);
        dfs_sub(grid, x, y + 1);
    }
};
