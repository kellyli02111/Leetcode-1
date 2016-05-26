class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int sizem = matrix.size();
        vector<int> res;
        if(sizem == 0){
            return res;
        }
        int sizen = matrix[0].size();
        if(sizen == 0 ){
            return res;
        }
        int nlvl = (min(sizem, sizen) + 1) / 2;
        for(int i = 0; i < nlvl; i++){
            int lastRow = sizem - 1 - i;
            int lastCol = sizen - 1 - i;
            if(lastRow == i){
                for(int j = i; j <= lastCol; j++){
                    res.push_back(matrix[i][j]);
                }
                return res;
            }
            if(lastCol == i){
                for(int j = i; j <= lastRow; j++){
                    res.push_back(matrix[j][i]);
                }
                return res;
            }
            for(int j = i; j < lastCol; j++){
                res.push_back(matrix[i][j]);
            }
            for(int j = i; j < lastRow; j++){
                res.push_back(matrix[j][lastCol]);
            }
            for(int j = lastCol; j > i; j--){
                res.push_back(matrix[lastRow][j]);
            }
            for(int j = lastRow; j > i; j--){
                res.push_back(matrix[j][i]);
            }
        }
        return res;
    }
};
