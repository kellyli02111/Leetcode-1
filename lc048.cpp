class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> matrixNew(n, vector<int>(n, 0));
        if (n > 0){
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    matrixNew[j][n-1-i] = matrix[i][j];
                }
            }
            matrix = matrixNew;
        }
    }
};

//定义全0空矩阵
//vector<vector<int>> matrixNew(n, vector<int>(n, 0));
