class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res(A.size(), vector<int>(B[0].size(), 0));
        int m = A.size();
        int n = A[0].size();
        int p = B[0].size();
        for(int i = 0; i < m; i++){
            for(int k = 0; k < n; k++){
                if(A[i][k] != 0){
                    for(int j = 0; j < p; j++){
                        if(B[k][j] != 0){
                            res[i][j] = res[i][j] + A[i][k] * B[k][j];
                        }
                    }
                }
            }
        }
        return res;
    }
};
