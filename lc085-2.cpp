class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> longestOne(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            if(matrix[i][0] == '1'){
                longestOne[i][0] = 1;
            }
            else{
                longestOne[i][0] = 0;
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == '1'){
                    longestOne[i][j] = longestOne[i][j - 1] + 1;
                }
                else{
                    longestOne[i][j] = 0;
                }
            }
        }
        int res = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int width = INT_MAX;
                int k = i;
                while(k >= 0){
                    width = min(width, longestOne[k][j]);
                    res = max(res, (i - k + 1) * width);
                    k--;
                }
                
            }
        }
        return res;
    }
};
