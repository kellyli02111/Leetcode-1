class NumMatrix {
    vector<vector<int>> dp;
public:
    NumMatrix(vector<vector<int>> matrix) {
        dp = matrix;
        if(matrix.size() == 0 || matrix[0].size() == 0) return;
        for(int i = 1; i < matrix.size(); i++){
            dp[i][0] = dp[i - 1][0] + matrix[i][0];
        }
        for(int j = 1; j < matrix[0].size(); j++){
            dp[0][j] = dp[0][j - 1] + matrix[0][j];
        }
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 1; j < matrix[0].size(); j++){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return (getNum(row2, col2) - getNum(row2, col1 - 1) - getNum(row1 - 1, col2) + getNum(row1 - 1, col1 - 1));
    }
    
    int getNum(int x, int y){
        if(x < 0 || y < 0) return 0;
        return dp[x][y];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
