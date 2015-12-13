class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int row0Zero = 0;
        int col0Zero = 0;
        for(int i = 0; i < n; i++){
            if(matrix[0][i] == 0){
                row0Zero = 1;
                break;
            }
        }
        for(int i = 0; i < m; i++){
            if(matrix[i][0] == 0){
                col0Zero = 1;
                break;
            }
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1; i < m; i++){
            if(matrix[i][0] == 0){
                for(int j = 1; j < n; j++){
                    matrix[i][j] = 0;
                }
            }
        }
        for(int j = 1; j < n; j++){
            if(matrix[0][j] == 0){
                for(int i = 1; i < m; i++){
                    matrix[i][j] = 0;
                }
            }
        }
        if(row0Zero == 1){
            for(int i = 0; i < n; i++){
                matrix[0][i] = 0;
            }
        }
        if(col0Zero == 1){
            for(int i = 0; i < m; i++){
                matrix[i][0] = 0;
            }
        }
    }
};
