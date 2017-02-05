class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> res;
        if(m <= 0 || n <= 0) return res;
        vector<int> uf(m * n, -1);
        vector<int> sz(m * n, 1);
        vector<vector<int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int count = 0;
        for(int i = 0; i < positions.size(); i++){
            int x = positions[i].first;
            int y = positions[i].second;
            int tmp = x * n + y;
            if(uf[tmp] != -1) continue;
            uf[tmp] = tmp;
            count++;
            for(int j = 0; j < dir.size(); j++){
                int nextX = x + dir[j][0];
                int nextY = y + dir[j][1];
                if(nextX < 0 || nextX >= m || nextY < 0 || nextY >= n || (uf[nextX * n + nextY] == -1)) continue;
                int rootP = findRoot(uf, tmp);
                int rootQ = findRoot(uf, nextX * n + nextY);
                if(rootP != rootQ){
                    if(sz[rootP] < sz[rootQ]){
                        uf[rootP] = uf[rootQ];
                        sz[rootQ] = sz[rootQ] + sz[rootP];
                    }
                    else{
                        uf[rootQ] = uf[rootP];
                        sz[rootP] = sz[rootP] + sz[rootQ];
                    }
                    count--;
                }
            }
            res.push_back(count);
        }
        return res;
    }
    
    int findRoot(vector<int>& uf, int p){
        int q = p;
        while(uf[q] != q){
            q = uf[q];
        }
        while(uf[p] != p){
            int r = p;
            p = uf[p];
            uf[r] = q;
        }
        
        return q;
    }
};
