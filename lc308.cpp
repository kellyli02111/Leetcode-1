//http://www.cnblogs.com/grandyang/p/5300458.html
class NumMatrix {
    vector<vector<int>> segTree;
    vector<vector<int>> data;
public:
    NumMatrix(vector<vector<int>> matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return;
        int m = matrix.size();
        int n = matrix[0].size();
        segTree.resize(m + 1, vector<int>(n + 1, 0));
        data.resize(m + 1, vector<int>(n + 1, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                update(i, j, matrix[i][j]);
            }
        }
    }
    
    void update(int row, int col, int val) {
        int diff = val - data[row + 1][col + 1];
        for(int i = row + 1; i < data.size(); i = i + (i & (i ^ (i - 1)))){
            for(int j = col + 1; j < data[0].size(); j = j + (j & (j ^ (j - 1)))){
                segTree[i][j] = segTree[i][j] + diff;
            }
        }
        data[row + 1][col + 1] = val;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return getSum(row2, col2) - getSum(row1 - 1, col2) - getSum(row2, col1 - 1) + getSum(row1 - 1, col1 - 1);
    }
    
    int getSum(int row, int col){
        int res = 0;
        for(int i = row + 1; i > 0; i = i - (i & (i ^ (i - 1)))){
            for(int j = col + 1; j > 0; j = j - (j & (j ^ (j - 1)))){
                res = res + segTree[i][j];
            }
        }
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */
