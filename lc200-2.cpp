class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<int> uf(m * n, 0);
        vector<int> sz(m * n, 1);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                uf[i * n + j] = i * n + j;
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != '0'){
                    int tmp = i * n + j;
                    if((inside(i - 1, j, m, n) && grid[i - 1][j] == '1')){
                        union_find(uf, sz, tmp, tmp - n);
                    }
                    if((inside(i + 1, j, m, n) && grid[i + 1][j] == '1')){
                        union_find(uf, sz, tmp, tmp + n);
                    }
                    if((inside(i, j - 1, m, n) && grid[i][j - 1] == '1')){
                        union_find(uf, sz, tmp, tmp - 1);
                    }
                    if((inside(i, j + 1, m, n) && grid[i][j + 1] == '1')){
                        union_find(uf, sz, tmp, tmp + 1);
                    }
                }
            }
        }
        
        int res = 0;
        for(int i = 0; i < m * n; i++){
            if(uf[i] == i && grid[i / n][i % n] != '0'){
                res++;
            }
        }
        return res;
    }
    
    int find(vector<int>& uf, int i){
        while(uf[i] != i){
            i = uf[i];
        }
        return i;
    }
    
    bool inside(int i, int j, int m, int n){
        return (i >= 0 && i < m && j >= 0 && j < n);
    }
    
    void union_find(vector<int>& uf, vector<int>& sz, int p, int q){
        int rootP = find(uf, p);
        int rootQ = find(uf, q);
        if(sz[rootP] < sz[rootQ]){
            sz[rootQ] = sz[rootQ] + sz[rootP];
            uf[rootP] = uf[rootQ];
        }
        else{
            sz[rootP] = sz[rootP] + sz[rootQ];
            uf[rootQ] = uf[rootP];
        }
    }
};
