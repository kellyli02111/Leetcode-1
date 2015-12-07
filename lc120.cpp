class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty()) return 0;
        vector<vector<int>> newTriangle;
        newTriangle = triangle;
        int n = triangle.size();
        for(int i = 1; i<n; i++){
            newTriangle[i][0] = newTriangle[i-1][0]+triangle[i][0];
            newTriangle[i][i] = newTriangle[i-1][i-1]+triangle[i][i];
        }
        for(int i = 2; i<n; i++){
            for(int j = 1; j<i; j++){
                newTriangle[i][j] = min(newTriangle[i-1][j-1],newTriangle[i-1][j]) + triangle[i][j];
            }   
        }
        int res = newTriangle[n-1][0];
        for(int i = 1; i<n; i++){
            if(newTriangle[n-1][i] < res){
                res = newTriangle[n-1][i];
            }
        }
        return res;
    }
};
