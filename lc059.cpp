class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int nlvl = n / 2;
        int val = 1;
        vector<vector<int>> res(n, vector<int>(n, 0));
        for(int i = 0; i < nlvl; i++){
            int lastInd = n - 1 - i;
            for(int j = i; j < lastInd; j++){
                res[i][j] = val;
                val++;
            }
            for(int j = i; j < lastInd; j++){
                res[j][lastInd] = val;
                val++;
            }
            for(int j = lastInd; j > i; j--){
                res[lastInd][j] = val;
                val++;
            }
            for(int j = lastInd; j > i; j--){
                res[j][i] = val;
                val++;
            }
        }
        if(n % 2 == 1){
            res[n / 2][n / 2] = val;
        }
        return res;
    }
};
