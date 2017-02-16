//http://www.cnblogs.com/grandyang/p/5297683.html
class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int res = INT_MAX;
        int target = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> sum = grid;
        vector<vector<int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    res = INT_MAX;
                    //如果出现island情况，接下来不会被执行，res会停留在INT_MAX
                    vector<vector<int>> dist = grid;
                    queue<pair<int, int>> q;
                    q.push(make_pair(i, j));
                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        for(int k = 0; k < dirs.size(); k++){
                            int nextX = x + dirs[k][0];
                            int nextY = y + dirs[k][1];
                            if(nextX >= 0 && nextX < m && nextY >= 0 && nextY < n && grid[nextX][nextY] == target){
                                grid[nextX][nextY]--;
                                dist[nextX][nextY] = dist[x][y] + 1;
                                sum[nextX][nextY] = sum[nextX][nextY] + dist[nextX][nextY] - 1;
                                res = min(res, sum[nextX][nextY]);
                                q.push(make_pair(nextX, nextY));
                            }
                        }
                    }
                    target--;
                }
            }
        }
        if(res == INT_MAX) return -1;
        return res;
    }
};
